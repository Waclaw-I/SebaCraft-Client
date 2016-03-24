#include "MainMenu.h"
#include "Button.h"
#include "GraphMethods.h"
#include "SFML\Graphics.hpp"

#include "TextureHolder.h"

#include <iostream>

using namespace sf;

MainMenu::MainMenu()
{

	
	
	resolutionX = 600;
	resolutionY = 600; // narazie na sztywno. Potrzeba menu do wyboru

	menuWindow = new RenderWindow(VideoMode(resolutionX, resolutionY, 32), "SebaCraft");

	Button bStart(100, 60, TextureHolder::getMenuButtonTexture(0), TextureHolder::getMenuButtonTexture(1), TextureHolder::getMenuButtonTexture(2));
	
	bStart.setPosition((resolutionX/2 - bStart.getWidth()/2), (resolutionY/2 - bStart.getHeight()/2 - 200));

	
	
	
	backgroundTexture.loadFromFile("Graphs/Menu/MenuBackground.jpg");
	
	backgroundSprite.setTexture(backgroundTexture);
	GraphMethods::ScaleSprite(backgroundSprite, resolutionX, resolutionY);


	while (menuWindow->isOpen())
	{
		Event event;

		while (menuWindow->pollEvent(event))
		{
			if (event.type == Event::Closed) menuWindow->close();
		}

		if (bStart.isMouseOver(*menuWindow)) bStart.activateHoveredSprite();
		else bStart.activateIdleSprite();
		if (bStart.isButtonPressed(*menuWindow)) bStart.activatePressedSprite();

		menuWindow->clear(Color::Cyan);
		menuWindow->draw(backgroundSprite);
		menuWindow->draw(bStart.getSprite());
		menuWindow->display();
	}
}