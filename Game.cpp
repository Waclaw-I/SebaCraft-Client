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

void ThreadProc(ClientData & myClient)
{
	string message; // for chat
	while (GameLogic::getGameOn())
	{
		// CHAT FUNCTION (CONSOLE FOR NOW)
		getline(cin, message);
		myClient.sendMessage(message);
	}
}

Game::Game(ClientData & myClient)
{
	GameLogic::setGameOn(true);
	thread t1(ThreadProc, myClient);

	resolutionX = GameLogic::getResolutionX();
	resolutionY = GameLogic::getResolutionY();

	scaleFactorX = static_cast<double>(resolutionX) / static_cast<double>(VideoMode::getDesktopMode().width);
	scaleFactorY = static_cast<double>(resolutionY) / static_cast<double>(VideoMode::getDesktopMode().height);

	GUIpanel mainPanel;
	Player player("Waclaw");

	


	if (resolutionX == VideoMode::getDesktopMode().width && resolutionY == VideoMode::getDesktopMode().height)
		gameWindow = new RenderWindow(VideoMode(100, 100, 32), "SebaCraft", Style::Fullscreen);

	else gameWindow = new RenderWindow(VideoMode(resolutionX, resolutionY, 32), "SebaCraft");

	View playerCamera;
	playerCamera = gameWindow->getDefaultView();
	playerCamera.setViewport(FloatRect(0, 0, 1, 1));

	backgroundTexture.loadFromFile("Graphs/Game/gameBackground.png");

	backgroundSprite.setTexture(backgroundTexture);
	GraphMethods::ScaleSprite(backgroundSprite, resolutionX, resolutionY);
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
					gameWindow->close();
					GameLogic::setGameOn(false);
				}
			}

			playerCamera.setCenter(player.getGlobalPositionX(), player.getGlobalPositionY());
			mainPanel.getGraph().setPosition(player.getGlobalPositionX() - resolutionX/2, player.getGlobalPositionY() - resolutionY/2);
			gameWindow->setView(playerCamera);

			PlayerController::Moving(&player);
			DisplayController::UpdatePlayerGraph(&player);

			gameWindow->clear(Color::Black);
			gameWindow->draw(backgroundSprite);
			gameWindow->draw(mainPanel.getGraph());
			gameWindow->draw(player.getGraph());

			gameWindow->display();

			accumulator -= timeStep;
		}
		
	}
}