#pragma once
#include "SFML\Graphics.hpp"

class MainMenu
{
private:
	int resolutionX;
	int resolutionY;
	bool Fullscreen;
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	sf::RenderWindow * menuWindow;

public:

	MainMenu();
};