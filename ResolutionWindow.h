#pragma once
#include "SFML\Graphics.hpp"

class ResolutionWindow
{
private:
	int resolutionX;
	int resolutionY;
	bool Fullscreen;
	sf::Texture backgroundTexture;
	sf::Sprite  backgroundSprite;
	sf::RenderWindow * resolutionWindow;

public:

	ResolutionWindow();
};