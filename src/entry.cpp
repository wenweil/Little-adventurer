#include "application/game.h"

using namespace melodramatic;

int main (){

    game* game = game::getInstance();
    
    game->init();

    game->run();

    glfwDestroyWindow(game->getWindow());

    glfwTerminate();

    return 0;
}