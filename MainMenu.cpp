#include "MainMenu.h"
#include "GraphMethods.h"
#include "SFML\Graphics.hpp"

#include <iostream>

using namespace sf;

MainMenu::MainMenu()
{
	
	resolutionX = 800;
	resolutionY = 600; // narazie na sztywno. Potrzeba menu do wyboru

	menuWindow = new RenderWindow(VideoMode(resolutionX, resolutionY, 32), "SebaCraft");

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
		menuWindow->display();
	}
}