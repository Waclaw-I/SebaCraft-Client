#include "PlayerController.h"

using namespace sf;
using namespace std;


void PlayerController::Moving(Player * player)
{
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		player->rotateLeft();
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		player->rotateRight();
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		player->accelerate();
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		player->stop();
	}

	player->move();
}