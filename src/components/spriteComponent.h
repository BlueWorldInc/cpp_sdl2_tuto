#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include <SDL2/SDL.h>
#include "../textureManager.h"
#include "../assetManager.h"
#include "../Animation.h"

class SpriteComponent: public Component {
    private:
        TransformComponent* transform;
        SDL_Texture* texture;
        SDL_Rect sourceRectangle;
        SDL_Rect destinationRectangle;
        bool isAnimated;
        int numFrames;
        int animationSpeed;
        bool isFixed;
        std::map<std::string, Animation> animations;
        std::string currentAnimationName;
        unsigned int animationIndex = 0;

    public:
        SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

        SpriteComponent(const char* filePath) {
            this->isAnimated = false;
            this->isFixed = false;
            setTexture(filePath);
        }

        SpriteComponent(const char* filePath, bool isFixed) {
            this->isAnimated = false;
            this->isFixed = isFixed;
            setTexture(filePath);
        }



        SpriteComponent(std::string filePath, int numFrames, int animationSpeed, bool hasDirections, bool isFixed) {
            this->isAnimated = true;
            this->numFrames = numFrames;
            this->animationSpeed = animationSpeed;
            this->isFixed = isFixed;

            if (hasDirections) {
                Animation downAnimation = Animation(0, numFrames, animationSpeed);
                Animation rightAnimation = Animation(1, numFrames, animationSpeed);
                Animation leftAnimation = Animation(2, numFrames, animationSpeed);
                Animation upAnimation = Animation(3, numFrames, animationSpeed);
                animations.emplace("DownAnimation", downAnimation);
                animations.emplace("RightAnimation", downAnimation);
                animations.emplace("LeftAnimation", downAnimation);
                animations.emplace("UpAnimation", downAnimation);
                this->animationIndex = 0;
                this->currentAnimationName = "DownAnimation";
            } else {
                Animation singleAnimation = Animation(0, numFrames, animationSpeed);
                animations.emplace("SingleAnimation", singleAnimation);
                this->animationIndex = 0;
                this->currentAnimationName = "SingleAnimation";
            }

            this->Play(this->currentAnimationName);
            this->setTexture(filePath);
        }

        void Play(std::string animationName) {
            numFrames = animations[animationName].numFrames;
            animationIndex = animations[animationName].index;
            animationSpeed = animations[animationName].animationSpeed;
            currentAnimationName = animationName;
        }

        void setTexture(std::string assetTextureId) {
            texture = Game::assetManager->getTexture(assetTextureId);
        }

        void initialize() override {
            transform = owner->GetComponent<TransformComponent>();
            sourceRectangle.x = 0;
            sourceRectangle.y = 0;
            sourceRectangle.w = transform->width;
            sourceRectangle.h = transform->height;

        }

        void update(float deltaTime) override {
            if (this->isAnimated) {
                sourceRectangle.x = sourceRectangle.w * static_cast<int>((SDL_GetTicks() / animationSpeed) % numFrames);
            }
            sourceRectangle.y = animationIndex * transform->height;

            destinationRectangle.x = static_cast<int>(transform->position.x);
            destinationRectangle.y = static_cast<int>(transform->position.y);
            destinationRectangle.w = transform->width * transform->scale;
            destinationRectangle.h = transform->height * transform->scale;

        }

        void render() override {
            TextureManager::draw(texture, sourceRectangle, destinationRectangle, spriteFlip);
        }
};

#endif