#pragma once
#include "Player.h"

#include <SFML/Graphics.hpp>

class PlayerController
{
	friend class Player;

public:

	static void Moving(Player *);
};