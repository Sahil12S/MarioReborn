#pragma once
#include <iostream>
#include <fstream>

#ifndef DEBUG
#define Debug(x) std::cout << "\033[34m[DEBUG] \033[0m" << x << std::endl;
#else
#define Debug(x)
#endif

#ifndef ERROR
#define Error(err, name) std::cout << "\033[31m[ERROR] \033[0m" << err << " " << name << std::endl;
#else
#define Error(err)
#endif

#define SCREEN_WIDTH 1366
#define SCREEN_HEIGHT 768

#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 90

#define SPLASH_SCENE_BACKGROUND_FILEPATH "../Resources/img/SplashBackground.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "../Resources/img/mainBackground.png"
#define GAME_BACKGROUND_FILEPATH "../Resources/img/background.png"

#define MAIN_MENU_FONT_FILEPATH "../Resources/font/OrangeJuice.ttf"
#define BUTTON_FONT_FILEPATH "../Resources/font/NationalCartoon.ttf"
#define DEBUG_FONT_FILEPATH "../Resources/font/Alexandria.ttf"

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
#define GENERAL_KEY_BIND_FILEPATH "../Resources/KeyBindings/KeyBinds.ini"
#define GAMESTATE_KEY_BIND_FILEPATH "../Resources/KeyBindings/GameStateKeyBinds.ini"
#define MAIN_MENU_KEY_BIND_FILEPATH "../Resources/KeyBindings/MainMenuKeyBinds.ini"
#define SETTINGS_STATE_KEY_BIND_FILEPATH "../Resources/KeyBindings/SettingsStateKeyBinds.ini"
#define PAUSE_STATE_KEY_BIND_FILEPATH "../Resources/KeyBindings/PauseStateKeyBinds.ini"

enum ButtonState
{
    eIdle = 0,
    eHover,
    eActive
};

enum MarioMovement
{
    eLeft,
    eRight,
    eJump,
    eRun
};

enum EntityStates
{
    eAlive,
    eDead
};

// Enums for mario's states