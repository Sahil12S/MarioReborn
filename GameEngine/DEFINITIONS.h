#pragma once
#include <iostream>
#include <fstream>

#ifndef DEBUG
#define Debug(x) std::cout << "\033[34m[DEBUG] \033[0m" << x << std::endl;
#else
#define Debug(x)
#endif

#define SCREEN_WIDTH 1366
#define SCREEN_HEIGHT 768

#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 90

#define SPLASH_SCENE_BACKGROUND_FILEPATH "../Resources/img/SplashBackground.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "../Resources/img/mainBackground.png"
#define MAIN_MENU_FONT_FILEPATH "../Resources/font/OrangeJuice.ttf"
#define BUTTON_FONT_FILEPATH "../Resources/font/NationalCartoon.ttf"
#define DEBUG_FONT_FILEPATH "../Resources/font/Alexandria.ttf"

/*#define PLAY_BUTTON_FILEPATH "../Resources/img/PlayButton.png"
#define EXIT_BUTTON_FILEPATH "../Resources/img/ExitButton.png"
#define SETTINGS_BUTTON_FILEPATH "../Resources/img/SettingsButton.png"
#define HOME_BUTTON_FILEPATH "../Resources/img/HomeButton.png"*/

#define MARIO_IDLE_FILEPATH "../Resources/img/Mario_Idle.png"
#define MARIO_WALK_01_FILEPATH "../Resources/img/Mario_Walk_01.png"
#define MARIO_WALK_02_FILEPATH "../Resources/img/Mario_Walk_02.png"
#define MARIO_WALK_03_FILEPATH "../Resources/img/Mario_Walk_03.png"
#define MARIO_JUMP_FILEPATH "../Resources/img/Mario_Jump.png"
#define MARIO_TURN_FILEPATH "../Resources/img/Mario_Turn.png"

#define GRAVITY 110.0f
#define JUMP_SPEED 100.0f

#define JUMP_DURATION 0.6f

#define WALKING_ANIMATION_DURATION 0.2f

#define SPLASH_STATE_SHOW_TIME 0.5f
#define ENTITY_MOVEMENT_SPEED 110.0f

// Key binds
#define GENERAL_KEY_BIND_FILEPATH "../Resources/KeyBinds.ini"
#define GAMESTATE_KEY_BIND_FILEPATH "../Resources/GameStateKeyBinds.ini"
#define MAIN_MENU_KEY_BIND_FILEPATH "../Resources/MainMenuKeyBinds.ini"

enum ButtonState
{
    eIdle = 0,
    eHover,
    eActive
};

enum MarioDirection
{
    eLeft = -1,
    eRight = 1
};

// Enums for mario's states