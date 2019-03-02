#pragma once
#ifndef MARIO_H
#define MARIO_H

#include "PlayableCharacter.h"

class Mario : public PlayableCharacter
{
public:
	Mario();

	bool virtual handleInput();
};

#endif // !MARIO_H