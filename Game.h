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
	sf::Texture backgroundTexture;
	sf::Sprite  backgroundSprite;
	sf::RenderWindow * gameWindow;

public:

	Game(ClientData & myClient);
};