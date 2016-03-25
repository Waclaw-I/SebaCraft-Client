#include "MainMenu.h"
#include "Button.h"
#include "GraphMethods.h"
#include "SFML\Graphics.hpp"

#include "TextureHolder.h"
#include "ResolutionWindow.h"

#include <iostream>

using namespace sf;

MainMenu::MainMenu()
{

	
	
	resolutionX = 600;
	resolutionY = 600; // narazie na sztywno. Potrzeba menu do wyboru

	menuWindow = new RenderWindow(VideoMode(resolutionX, resolutionY, 32), "SebaCraft");

	Button bLogin(100, 60, TextureHolder::getMenuButtonTexture(0), TextureHolder::getMenuButtonTexture(1), TextureHolder::getMenuButtonTexture(2));
	Button bRegister(100, 60, TextureHolder::getMenuButtonTexture(3), TextureHolder::getMenuButtonTexture(4), TextureHolder::getMenuButtonTexture(5));
	Button bResolution(100, 60, TextureHolder::getMenuButtonTexture(6), TextureHolder::getMenuButtonTexture(7), TextureHolder::getMenuButtonTexture(8));
	Button bExit(100, 60, TextureHolder::getMenuButtonTexture(9), TextureHolder::getMenuButtonTexture(10), TextureHolder::getMenuButtonTexture(11));
	
	bLogin.setPosition((resolutionX/2 - bLogin.getWidth()/2), (resolutionY/2 - bLogin.getHeight()/2 - 200));
	bRegister.setPosition((resolutionX / 2 - bRegister.getWidth() / 2), (resolutionY / 2 - bRegister.getHeight() / 2 - 100));
	bResolution.setPosition((resolutionX / 2 - bRegister.getWidth() / 2), (resolutionY / 2 - bRegister.getHeight() / 2));
	bExit.setPosition((resolutionX / 2 - bRegister.getWidth() / 2), (resolutionY / 2 - bRegister.getHeight() / 2 + 100));

	
	
	
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

		bLogin.changeVisibleSprite(*menuWindow);
		bRegister.changeVisibleSprite(*menuWindow);
		bResolution.changeVisibleSprite(*menuWindow);
		bExit.changeVisibleSprite(*menuWindow);

		if (bResolution.isButtonPressed(*menuWindow)) ResolutionWindow * resolution = new ResolutionWindow();
		if (bExit.isButtonPressed(*menuWindow)) menuWindow->close();

		menuWindow->clear(Color::Cyan);
		menuWindow->draw(backgroundSprite);
		menuWindow->draw(bLogin.getSprite());
		menuWindow->draw(bRegister.getSprite());
		menuWindow->draw(bResolution.getSprite());
		menuWindow->draw(bExit.getSprite());
		menuWindow->display();
	}
}