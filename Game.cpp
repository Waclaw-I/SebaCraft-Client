#include "Game.h"
#include "GameLogic.h"
#include "GraphMethods.h"
#include "Button.h"
#include "TextureHolder.h"
#include "GUIpanel.h"
#include "Player.h"
#include "PlayerController.h"
#include "DisplayController.h"
#include "UsefulMethods.h"
#include "BulletsController.h"

#include "SmallFighter.h"
#include "Trasher.h"

#include <thread>
#include "SFML\Graphics.hpp"

#include <iostream>

using namespace sf;

Game::Game(ClientData & myClient)
{
	GameLogic::getClientData() = myClient;
	string typedText;
	int lineLength = 0;

	GameLogic::setGameOn(true);

	thread getInformations (&ClientData::ClientThreadGetInfo, &myClient); // NOWY WATEK DO POBIERANIA INFORMACJI Z SERWERA
	getInformations.detach();

	currentlyTyping = false;

	resolutionX = GameLogic::getResolutionX();
	resolutionY = GameLogic::getResolutionY();

	scaleFactorX = static_cast<double>(resolutionX) / static_cast<double>(VideoMode::getDesktopMode().width);
	scaleFactorY = static_cast<double>(resolutionY) / static_cast<double>(VideoMode::getDesktopMode().height);

	
	Player * player = new Player( myClient.getNickname(), UsefulMethods::getSpaceShipType(myClient.getShipType()), myClient.getID());

	thread sendInformations(&ClientData::ClientThreadSendInfo, &myClient, player); // NOWY WATEK DO WYSYLANIA INFORMACJI DO SERWERA
	sendInformations.detach();


	GUIpanel mainPanel(player);
	mainPanel.updatePanel();


	


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

	while (gameWindow->isOpen() && player->getShip()->isAlive())
	{
		if (!myClient.getCanStay())
		{
			gameWindow->close(); // if there is something wrong (for example no room on the server)
			
		}
		accumulator += timer.restart().asSeconds();

		if (accumulator >= timeStep) // timer
		{
			Event event;

			while (gameWindow->pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					GameLogic::setGameOn(false);
					string left = ""; // plain text to use send method
					myClient.sendLeftAlert(left);
					gameWindow->close();
				}
				if (event.key.code == Keyboard::Escape)
				{
					GameLogic::setGameOn(false);
					string left = ""; // plain text to use send method
					myClient.sendLeftAlert(left);
					gameWindow->close();
					
				}
				if (event.type == Event::KeyReleased && event.key.code == Keyboard::Return)
				{
					currentlyTyping = !currentlyTyping;
				}

				if (event.type == sf::Event::TextEntered && currentlyTyping == true) //THIS ONE DESPERATELY NEEDS TO BE IN A SEPARATE METHOD
				{
					if (event.text.unicode < 128)
					{
						if (event.text.unicode == 13) // ENTER ALSO KNOWN AS RETURN
						{
							string chatMessage = myClient.getNickname() + ": " + typedText;
							if (typedText != "")
							{
								myClient.sendMessage(chatMessage); // WHEN WE HIT ENTER, WE SEND OUR MESSAGE TO THE SERVER
								chatMessage = "You: " + typedText;
								mainPanel.addToChat(chatMessage, Color::White); // AND TO CHAT
							}
							typedText = "";
							lineLength = 0;
							mainPanel.getEnteredText().setString(typedText);

						}
						if (event.text.unicode == 8) // BACKSPACE
						{
							typedText.erase(typedText.size() - 1, 1);
							lineLength--;
							mainPanel.getEnteredText().setString(typedText);
						}
						if (event.text.unicode != 8 && event.text.unicode != 13)
						{
							typedText += static_cast<char>(event.text.unicode);
							lineLength++;
							if (lineLength > 40)
							{
								typedText += "\n";
								lineLength = 0;
							}
							mainPanel.getEnteredText().setString(typedText);
						}
					}
					
				}

			}
			if (myClient.getNewMessageConfirmation()) // displaying messages from other players
			{
				mainPanel.addToChat(myClient.getReceivedChatMessage(), Color::Red);
				myClient.setNewMessageConfirmation(false);
			}

			mainPanel.updatePosition();
			mainPanel.updatePanel();


			playerCamera.setCenter(player->getShip()->getPositionX() - mainPanel.getSizeX()/2 + player->getShip()->getSizeX()/2, player->getShip()->getPositionY());
			mainPanel.getGraph().setPosition(mainPanel.getPositionX(), mainPanel.getPositionY());
			background.setPosition(player->getShip()->getPositionX() - resolutionX / 2, player->getShip()->getPositionY() - resolutionY / 2);
			background2.setPosition(player->getShip()->getPositionX()*0.75 - resolutionX / 2, player->getShip()->getPositionY()*0.75 - resolutionY / 2);
			gameWindow->setView(playerCamera);

			PlayerController::Moving(player);
			player->getShip()->move();
			player->updateGraphPosition();

			BulletsController::getBulletsController().controllBullets();
			BulletsController::getBulletsController().lookForCollisions(player);

			

			gameWindow->clear(Color::Black);
			gameWindow->draw(background);
			gameWindow->draw(background2);
			gameWindow->draw(player->getShip()->getGraph());
			for (int i = 0; i < GameLogic::getPlayersList().size(); i++)
			{
				GameLogic::getPlayersList()[i]->updateGraphPosition();
				gameWindow->draw(GameLogic::getPlayersList()[i]->getShip()->getGraph());
			}

			for (Bullet * x : BulletsController::getBulletsController().getBulletsInGame())
			{
				gameWindow->draw(x->getGraph());
			}

			gameWindow->draw(mainPanel.getGraph());
			gameWindow->draw(mainPanel.getCoordinatesX());
			gameWindow->draw(mainPanel.getCoordinatesY());
			gameWindow->draw(mainPanel.getPlayersAmount());
			gameWindow->draw(mainPanel.getHealth());
			gameWindow->draw(mainPanel.getSpeedDisplay());
			gameWindow->draw(mainPanel.getSpeedaDisplayDot());
			gameWindow->draw(mainPanel.getEnteredText());
			for (int i = 0; i < mainPanel.getChatMessages().size(); i++) 
			{
				gameWindow->draw(mainPanel.getChatMessages()[i]);
			}

			
			

			gameWindow->display();

			accumulator -= timeStep;
		}
		
	}
	gameWindow->close();
	GameLogic::setGameOn(false);
	string left = ""; // plain text to use send method
	myClient.sendLeftAlert(left);
	closesocket(myClient.getSocket());
}
