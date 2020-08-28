#include <iostream>
#include "./constants.h"
#include "./game.h"

int main(int argc, char* argv[]) {
    Game* game = new Game();
    game->initialize(WINDOW_WIDTH, WINDOW_HEIGHT);
        int i = 0;

    while (game->isRunning()) {
        game->processInput();
        game->update();
        game->render();
    }

    game->destroy();

    return 0;
}
