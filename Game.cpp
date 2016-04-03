#include "Game.h"
#include "GameLogic.h"
#include "GraphMethods.h"
#include "Button.h"
#include "TextureHolder.h"
#include "GUIpanel.h"
#include "Player.h"
#include "PlayerController.h"
#include "DisplayController.h"

#include <thread>
#include "SFML\Graphics.hpp"

#include <iostream>

using namespace sf;

Game::Game(ClientData & myClient)
{
	GameLogic::setGameOn(true);

	currentlyTyping = false;

	resolutionX = GameLogic::getResolutionX();
	resolutionY = GameLogic::getResolutionY();

	scaleFactorX = static_cast<double>(resolutionX) / static_cast<double>(VideoMode::getDesktopMode().width);
	scaleFactorY = static_cast<double>(resolutionY) / static_cast<double>(VideoMode::getDesktopMode().height);

	Player player("Waclaw", TextureHolder::getShipsTextures(0), 300, 300, 61, 51, 0); // need to change the way of doing this. Player should have a pointer to a pre-build ship and a name. Nothing more

	GUIpanel mainPanel(&player);
	mainPanel.updatePanel();

	string typedText;


	


	if (resolutionX == VideoMode::getDesktopMode().width && resolutionY == VideoMode::getDesktopMode().height)
		gameWindow = new RenderWindow(VideoMode(100, 100, 32), "SebaCraft", Style::Fullscreen);

	else gameWindow = new RenderWindow(VideoMode(resolutionX, resolutionY, 32), "SebaCraft");

	View playerCamera;
	playerCamera = gameWindow->getDefaultView();
	playerCamera.setViewport(FloatRect(0, 0, 1, 1));


	background.setTexture(TextureHolder::getBackgroundTextures(0));
	background2.setTexture(TextureHolder::getBackgroundTextures(1));
	GraphMethods::ScaleToResolution(background, 1400, 800, resolutionX, resolutionY);

	GraphMethods::ScaleToResolution(mainPanel.getGraph(), 800, 600, resolutionX, resolutionY);

	Clock timer;
	float accumulator = 0;
	float timeStep = 0.0166f; // 60FPS

	while (gameWindow->isOpen())
	{
		accumulator += timer.restart().asSeconds();

		if (accumulator >= timeStep) // timer
		{
			Event event;

			while (gameWindow->pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					GameLogic::setGameOn(false);
					gameWindow->close();
				}
				if (event.key.code == Keyboard::Escape)
				{
					GameLogic::setGameOn(false);
					gameWindow->close();
					
				}
				if (event.type == Event::KeyReleased && event.key.code == Keyboard::Return)
				{
					currentlyTyping = !currentlyTyping;
					cout << currentlyTyping;
				}

				if (event.type == sf::Event::TextEntered && currentlyTyping == true)
				{
					if (event.text.unicode < 128)
					{
						if (event.text.unicode == 13) // ENTER ALSO KNOWN AS RETURN
						{
							typedText = "";
							mainPanel.getEnteredText().setString(typedText);
							myClient.sendMessage(typedText); // WHEN WE HIT ENTER, WE SEND OUR MESSAGE TO THE SERVER
							break;
						}
						if (event.text.unicode == 8) // BACKSPACE
						{
							typedText.erase(typedText.size() - 1, 1);
							mainPanel.getEnteredText().setString(typedText);
						}
						if (event.text.unicode != 8 && event.text.unicode != 13)
						{
							typedText += static_cast<char>(event.text.unicode);
							mainPanel.getEnteredText().setString(typedText);
						}
					}
					
				}

			}


			mainPanel.updatePosition();
			mainPanel.updatePanel();


			playerCamera.setCenter(player.getPositionX(), player.getPositionY());
			mainPanel.getGraph().setPosition(mainPanel.getPositionX(), mainPanel.getPositionY());
			background.setPosition(player.getPositionX() - resolutionX / 2, player.getPositionY() - resolutionY / 2);
			background2.setPosition(player.getPositionX()*0.75 - resolutionX / 2, player.getPositionY()*0.75 - resolutionY / 2);
			gameWindow->setView(playerCamera);

			PlayerController::Moving(&player);
			player.move();
			DisplayController::UpdatePlayerGraph(&player);

			gameWindow->clear(Color::Black);
			gameWindow->draw(background);
			gameWindow->draw(background2);
			gameWindow->draw(player.getGraph());
			gameWindow->draw(mainPanel.getGraph());
			gameWindow->draw(mainPanel.getCoordinatesX());
			gameWindow->draw(mainPanel.getCoordinatesY());
			gameWindow->draw(mainPanel.getSpeedDisplay());
			gameWindow->draw(mainPanel.getSpeedaDisplayDot());
			gameWindow->draw(mainPanel.getEnteredText());

			gameWindow->display();

			accumulator -= timeStep;
		}
		
	}
}