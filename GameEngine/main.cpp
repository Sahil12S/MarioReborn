#include <iostream>
#include "Game.h"
#include "DEFINITIONS.h"

int main()
{
    MarioEngine::Game game( SCREEN_WIDTH, SCREEN_HEIGHT, "Mario Bros" );
    return EXIT_SUCCESS;
}