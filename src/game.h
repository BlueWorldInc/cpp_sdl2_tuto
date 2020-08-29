#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <../lib/glm/glm.hpp>
#include <../lib/glm/gtx/string_cast.hpp>
// #include <SDL2/SDL_image.h>
// #include <SDL2/SDL_ttf.h>

class Game {
    private:
        bool running;
        SDL_Window* window;
        SDL_Renderer* renderer;
    public:
        Game();
        ~Game();
        uint32_t ticksLastFrame;
        bool isRunning();
        void initialize(int width, int height);
        void processInput();
        void update();
        void render();
        void destroy();
};

#endif