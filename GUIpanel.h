#pragma once
#include "DrawableObject.h"
#include "Player.h"
#include "TextureHolder.h"
#include "SFML\Graphics.hpp"

using namespace sf;

class GUIpanel : public DrawableObject
{

private:
	Text CoordinatesX;
	Text CoordinatesY;

	Player * player;

	Sprite speedDisplay;
	Sprite speedDisplayDot;

	double dotIdlePositionX;
	double dotIdlePositionY;

	
public:
	GUIpanel(Player * player);

	void updatePosition();
	void updatePanel();

	Text & getCoordinatesX();
	Text & getCoordinatesY();

	Sprite & getSpeedDisplay();
	Sprite & getSpeedaDisplayDot();
};

