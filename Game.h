#pragma once
#include "SFML\Graphics.hpp"

class Game
{
private:
	int resolutionX;
	int resolutionY;

	double scaleFactorX;
	double scaleFactorY;

	bool Fullscreen;
	sf::Texture backgroundTexture;
	sf::Sprite  backgroundSprite;
	sf::RenderWindow * gameWindow;

public:

	Game();
};