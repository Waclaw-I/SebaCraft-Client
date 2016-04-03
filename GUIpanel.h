#pragma once
#include "DrawableObject.h"
#include "Player.h"
#include "TextureHolder.h"
#include "SFML\Graphics.hpp"

using namespace sf;

class GUIpanel : public DrawableObject
{

private:
	Text coordinatesX;
	Text coordinatesY;
	Text enteredText;

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
	Text & getEnteredText();

	Sprite & getSpeedDisplay();
	Sprite & getSpeedaDisplayDot();
};

