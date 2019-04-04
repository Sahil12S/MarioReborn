#pragma once
#include <iostream>
#include <fstream>

#ifndef DEBUG
#define Debug(x) std::cout << "\033[34m[DEBUG] \033[0m" << x << std::endl;
#else
#define Debug(x)
#endif

#define SCREEN_WIDTH 980
#define SCREEN_HEIGHT 600

#define SPLASH_SCENE_BACKGROUND_FILEPATH "../Resources/img/SplashBackground.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "../Resources/img/mainBackground.png"
#define MAIN_MENU_TILE_FILEPATH "../Resource/img/tile.png"

#define PLAY_BUTTON_FILEPATH "../Resources/img/PlayButton.png"

#define SPLASH_STATE_SHOW_TIME 1.0f
#define ENTITY_MOVEMENT_SPEED 100.0f

// Key binds
#define GENERAL_KEY_BIND_FILEPATH "../Resources/KeyBinds.ini"
#define GAMESTATE_KEY_BIND_FILEPATH "../Resources/GameStateKeyBinds.ini"
#define MAIN_MENU_KEY_BIND_FILEPATH "../Resources/MainMenuKeyBinds.ini"