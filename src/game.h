#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <../lib/glm/glm.hpp>
#include <../lib/glm/gtx/string_cast.hpp>
#include "./entity.h"
#include "./component.h"
#include "./entityManager.h"
// #include <SDL2/SDL_image.h>
// #include <SDL2/SDL_ttf.h>

class Game {
    private:
        bool running;
        SDL_Window* window;
    public:
        Game();
        ~Game();
        uint32_t ticksLastFrame = 0;
        bool isRunning() const;
        static SDL_Renderer* renderer;
        void loadLevel(int levelNumber);
        void initialize(int width, int height);
        void processInput();
        void update();
        void render();
        void destroy();
};

#endif