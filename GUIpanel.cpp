#include "GUIpanel.h"
#include "GameLogic.h"

#include <iostream>
using namespace std;

GUIpanel::GUIpanel(Player * player) : DrawableObject(0, 0, TextureHolder::getGUItextures(0), 200, 600, 0)
{

	this->player = player;

	double xFactor = static_cast<double>(GameLogic::getResolutionX()) / 800;
	double yFactor = static_cast<double>(GameLogic::getResolutionY()) / 600;

	this->sizeX *= xFactor; // we set text for basic resolution and scale it later
	this->sizeY *= yFactor;

	this->speedDisplay.setTexture(TextureHolder::getGUItextures(1));
	this->speedDisplay.setScale(xFactor, yFactor);
	this->speedDisplayDot.setTexture(TextureHolder::getGUItextures(2));
	this->speedDisplayDot.setScale(xFactor, yFactor);

	coordinatesX.setFont(TextureHolder::getFonts(0)); // we store our fonts there
	coordinatesY.setFont(TextureHolder::getFonts(0));
	enteredText.setFont(TextureHolder::getFonts(0));

	coordinatesX.setColor(Color::Black);
	coordinatesY.setColor(Color::Black);
	enteredText.setColor(Color::White);
	// IT NEEDS TO BE CHANGED INTO TEXTBOX.SIZE CHECKING INSTEAD OF NUMBER OF CHARACTERS
	if (GameLogic::getResolutionX() <= 640)
	{
		chatCharSize = 9;
		chatCharAmount = 15;
	}
	if (GameLogic::getResolutionX() == 800)
	{
		chatCharSize = 13;
		chatCharAmount = 15;
	}
	if (GameLogic::getResolutionX() == 1024)
	{
		chatCharSize = 16;
		chatCharAmount = 15;
	}
	if (GameLogic::getResolutionX() > 1024)
	{
		chatCharSize = (13 * (GameLogic::getResolutionX() / 800));
		chatCharAmount = 18;
	}



	updatePanel();

	if (GameLogic::getResolutionX() >= 800) // to prevent multiplying by 0
	{
		coordinatesX.setCharacterSize(15 * (GameLogic::getResolutionX() / 800));
		coordinatesY.setCharacterSize(15 * (GameLogic::getResolutionX() / 800));
		enteredText.setCharacterSize(15 * (GameLogic::getResolutionX() / 800));
	}
	else
	{
		coordinatesX.setCharacterSize(12);
		coordinatesY.setCharacterSize(12);
		enteredText.setCharacterSize(13);
	}
}

void GUIpanel::updatePosition()
{
	positionX = player->getShip().getPositionX() - GameLogic::getResolutionX() / 2;
	positionY = player->getShip().getPositionY() - GameLogic::getResolutionY() / 2;
}

void GUIpanel::updatePanel()
{
	coordinatesX.setString("X: " + to_string(static_cast<int>(player->getShip().getPositionX())));
	coordinatesY.setString("Y: " + to_string(static_cast<int>(player->getShip().getPositionY())));

	coordinatesX.setPosition(positionX + sizeX*0.10, positionY + sizeY*0.57);
	coordinatesY.setPosition(positionX + sizeX*0.10, positionY + sizeY*0.64);
	enteredText.setPosition(positionX + sizeX*1.5, positionY + sizeY*0.84);

	speedDisplay.setPosition(positionX + sizeX*0.45, positionY + sizeY*0.55);
	speedDisplayDot.setPosition(
		speedDisplay.getPosition().x + (85*speedDisplay.getScale().x)/2 - (7*speedDisplayDot.getScale().x)/2
		+ (player->getShip().getActualSpeedX()/player->getShip().getMaxSpeed())*((65 * speedDisplay.getScale().x) / 2),

		speedDisplay.getPosition().y + (85*speedDisplay.getScale().y)/2 - (7*speedDisplayDot.getScale().y)/2 
		+ (player->getShip().getActualSpeedY() / player->getShip().getMaxSpeed())*((65 * speedDisplay.getScale().y) / 2)
		);

	if (chatMessages.size() > 15)
	{
		chatMessages.erase(chatMessages.begin());
	}

	for (int i = 0; i < chatMessages.size(); i++)
	{
		chatMessages[i].setPosition(positionX + sizeX*0.10, positionY + sizeY*0.03 + (i*sizeY*0.03));
	}
}

Text & GUIpanel::getCoordinatesX() { return coordinatesX; }
Text & GUIpanel::getCoordinatesY() { return coordinatesY; }
Text & GUIpanel::getEnteredText() { return enteredText; }

vector <Text> & GUIpanel::getChatMessages() { return chatMessages; }
void GUIpanel::addToChat(string text, Color col)
{
	if (text.length() > chatCharAmount)
	{
		for (int i = 0; i < text.length(); i++)
		{
			if (text[i] == '\n') text.erase(i, 1); // usuwamy znaki konca linii
		}
		for (int i = 0; i < text.length(); i += chatCharAmount)
		{
			Text temp;
			temp.setColor(col);
			temp.setFont(TextureHolder::getFonts(0));
			temp.setCharacterSize(chatCharSize); // bigger screen means bigger size!
			temp.setString(text.substr(i, chatCharAmount));
			chatMessages.push_back(temp);
		}

	}
	else
	{
		Text newText;
		newText.setColor(col);
		newText.setFont(TextureHolder::getFonts(0));
		newText.setCharacterSize(11 * (GameLogic::getResolutionX() / 800)); // bigger screen means bigger size!
		newText.setString(text);

		chatMessages.push_back(newText);
	}
}

Sprite & GUIpanel::getSpeedDisplay() { return speedDisplay; }
Sprite & GUIpanel::getSpeedaDisplayDot() { return speedDisplayDot; }


