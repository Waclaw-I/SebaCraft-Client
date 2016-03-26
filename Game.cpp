#include "Game.h"
#include "GameLogic.h"
#include "GraphMethods.h"
#include "Button.h"
#include "TextureHolder.h"

#include "SFML\Graphics.hpp"

#include <iostream>

using namespace sf;

Game::Game()
{
	resolutionX = GameLogic::getResolutionX();
	resolutionY = GameLogic::getResolutionY();

	scaleFactorX = static_cast<double>(resolutionX) / static_cast<double>(VideoMode::getDesktopMode().width);
	scaleFactorY = static_cast<double>(resolutionY) / static_cast<double>(VideoMode::getDesktopMode().height);

	std::cout << scaleFactorX << endl;
	std::cout << scaleFactorY << endl;

	if (resolutionX == VideoMode::getDesktopMode().width && resolutionY == VideoMode::getDesktopMode().height)
		gameWindow = new RenderWindow(VideoMode(resolutionX, resolutionY, 32), "SebaCraft", Style::Fullscreen);

	else gameWindow = new RenderWindow(VideoMode(resolutionX, resolutionY, 32), "SebaCraft");

	backgroundTexture.loadFromFile("Graphs/Game/gameBackground.png");

	backgroundSprite.setTexture(backgroundTexture);
	GraphMethods::ScaleSprite(backgroundSprite, resolutionX, resolutionY);

	Button bTemp(100 * scaleFactorX, 60 * scaleFactorY, TextureHolder::getMenuButtonTexture(0), TextureHolder::getMenuButtonTexture(1), TextureHolder::getMenuButtonTexture(2));
	bTemp.setPosition((resolutionX / 2 - bTemp.getWidth() / 2), (resolutionY / 2 - bTemp.getHeight() / 2 ));

	while (gameWindow->isOpen())
	{
		Event event;

		while (gameWindow->pollEvent(event))
		{
			if (event.type == Event::Closed) gameWindow->close();
			if (event.key.code == Keyboard::Escape) gameWindow->close();
		}

		gameWindow->clear(Color::Black);
		gameWindow->draw(backgroundSprite);
		gameWindow->draw(bTemp.getSprite());

		gameWindow->display();
	}
}