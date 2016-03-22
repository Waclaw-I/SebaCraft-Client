#include "MainMenu.h"
#include "Button.h"
#include "GraphMethods.h"
#include "SFML\Graphics.hpp"

#include <iostream>

using namespace sf;

MainMenu::MainMenu()
{
	
	resolutionX = 800;
	resolutionY = 600; // narazie na sztywno. Potrzeba menu do wyboru

	menuWindow = new RenderWindow(VideoMode(resolutionX, resolutionY, 32), "SebaCraft");

	Texture idleStartTexture, hoveredStartTexture, pressedStartTexture;
	idleStartTexture.loadFromFile("Graphs\\bIdleStart.png");
	hoveredStartTexture.loadFromFile("Graphs\\bHoveredStart.png");
	pressedStartTexture.loadFromFile("Graphs\\bPressedStart.png");
	
	Sprite idleStartSprite, hoveredStartSprite, pressedStartSprite;

	idleStartSprite.setTexture(idleStartTexture);
	hoveredStartSprite.setTexture(hoveredStartTexture);
	pressedStartSprite.setTexture(pressedStartTexture);

	Button bStart(100, 60, idleStartSprite);
	bStart.setAdditionalSprites(idleStartSprite, hoveredStartSprite, pressedStartSprite); // we want to use additional Sprites for buttons
	bStart.setPosition(300, 300);

	bStart.activateHoveredSprite();

	backgroundTexture.loadFromFile("Graphs\\MenuBackground.jpg");
	
	
	backgroundSprite.setTexture(backgroundTexture);
	GraphMethods::ScaleSprite(backgroundSprite, resolutionX, resolutionY);


	while (menuWindow->isOpen())
	{
		Event event;

		while (menuWindow->pollEvent(event))
		{
			if (event.type == Event::Closed) menuWindow->close();
		}


		menuWindow->clear(Color::Cyan);
		menuWindow->draw(backgroundSprite);
		menuWindow->draw(bStart.getSprite());
		menuWindow->display();
	}
}