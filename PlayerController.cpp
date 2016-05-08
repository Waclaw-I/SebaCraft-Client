#include "PlayerController.h"
#include <iostream>

using namespace sf;
using namespace std;


void PlayerController::Moving(Player * player)
{
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		player->getShip()->rotateLeft();
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		player->getShip()->rotateRight();
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		player->getShip()->accelerate();
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		player->getShip()->stop();
	}
	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		player->getShip()->shoot();
	}
}