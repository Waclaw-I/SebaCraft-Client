#pragma once
#include "SFML\Graphics.hpp"
#include "ClientData.h"

class Game
{
private:
	int resolutionX;
	int resolutionY;

	double scaleFactorX; // we need that to scale sprites properly, depending on used resolution
	double scaleFactorY;

	bool Fullscreen;
	bool currentlyTyping;

	sf::Sprite background;
	sf::Sprite background2;
	sf::RenderWindow * gameWindow;

public:

	Game(ClientData & myClient);
};