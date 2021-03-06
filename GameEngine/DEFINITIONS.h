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


#define GAME_BACKGROUND_FILEPATH "../Resources/img/background.png"

#define MARIO_SHEET_FILEPATH "../Resources/img/Mario.png"

/*#define MARIO_IDLE_FILEPATH "../Resources/img/Mario_Idle.png"
#define MARIO_WALK_01_FILEPATH "../Resources/img/Mario_Walk_01.png"
#define MARIO_WALK_02_FILEPATH "../Resources/img/Mario_Walk_02.png"
#define MARIO_WALK_03_FILEPATH "../Resources/img/Mario_Walk_03.png"
#define MARIO_JUMP_FILEPATH "../Resources/img/Mario_Jump.png"
#define MARIO_TURN_FILEPATH "../Resources/img/Mario_Turn.png"*/

// Fonts
#define SCREEN_FONT_FILEPATH "../Resources/font/OrangeJuice.ttf"
#define BUTTON_FONT_FILEPATH "../Resources/font/NationalCartoon.ttf"
#define DEBUG_FONT_FILEPATH "../Resources/font/Alexandria.ttf"


enum ButtonState
{
    eBtnIdle = 0,
    eBtnHover,
    eBtnActive
};

#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 90

#define TEXT_IDLE_FILL_COLOR 70, 70, 70, 200
#define TEXT_HOVER_FILL_COLOR 250, 250, 250, 250
#define TEXT_ACTIVE_FILL_COLOR 20, 20, 20, 50

#define BUTTON_IDLE_FILL_COLOR 70, 70, 70, 0
#define BUTTON_HOVER_FILL_COLOR 150, 150, 150, 0
#define BUTTON_ACTIVE_FILL_COLOR 20, 20, 20, 0

#define BUTTON_TEXT_SIZE 50

#define TILE_HEIGHT 16
#define TILE_WIDTH 16
#define POWER_UP_TILE_FACTOR 2.f

#define GRAVITY 250.0f
#define JUMP_SPEED 250.0f

#define PLAYER_MOVEMENT_SPEED 110.0f
#define RUNNING_FACTOR 2.f

#define JUMP_DURATION 0.4f
#define WALK_ANIMATION_DURATION 12.f
#define SPLASH_STATE_SHOW_TIME 0.5f

// Key binds
#define GENERAL_KEY_BIND_FILEPATH "../Resources/KeyBindings/KeyBinds.ini"
#define GAMESTATE_KEY_BIND_FILEPATH "../Resources/KeyBindings/GameStateKeyBinds.ini"
#define MAIN_MENU_KEY_BIND_FILEPATH "../Resources/KeyBindings/MainMenuKeyBinds.ini"
#define SETTINGS_STATE_KEY_BIND_FILEPATH "../Resources/KeyBindings/SettingsStateKeyBinds.ini"
#define PAUSE_STATE_KEY_BIND_FILEPATH "../Resources/KeyBindings/PauseStateKeyBinds.ini"


enum MovementStates
{
    eIdle = 0,
    eMoving,
    eMovingLeft,
    eMovingRight,
    eJumping,
    eFalling,
    eRunningLeft,
    eRunningRight
};

enum EntityStates
{
    eAlive,
    eDead
};

// Enums for mario's states