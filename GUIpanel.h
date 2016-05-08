#pragma once
#include "DrawableObject.h"
#include "Player.h"
#include "TextureHolder.h"
#include "SFML\Graphics.hpp"
#include <vector>

using namespace sf;

class GUIpanel : public DrawableObject
{

public:
	GUIpanel(Player * player);

	void updatePosition();
	void updatePanel();

	Text & getCoordinatesX();
	Text & getCoordinatesY();
	Text & getPlayersAmount();
	Text & getHealth();
	Text & getEnteredText();

	Sprite & getSpeedDisplay();
	Sprite & getSpeedaDisplayDot();

	vector <Text> & getChatMessages();

	void addToChat(string text, Color col);

private:
	Text coordinatesX;
	Text coordinatesY;
	Text playersAmount;
	Text health;
	Text enteredText;

	vector <Text> chatMessages;

	Player * player;

	Sprite speedDisplay;
	Sprite speedDisplayDot;

	double dotIdlePositionX;
	double dotIdlePositionY;

	int chatCharSize;
	int chatCharAmount;
};

