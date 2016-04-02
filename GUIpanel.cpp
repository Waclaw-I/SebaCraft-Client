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

	cout << "X: " << sizeX << endl;
	cout << "Y: " << sizeY << endl;

	CoordinatesX.setFont(TextureHolder::getFonts(0)); // we store our fonts there
	CoordinatesY.setFont(TextureHolder::getFonts(0));

	CoordinatesX.setColor(Color::Black);
	CoordinatesY.setColor(Color::Black);


	updatePanel();

	if (GameLogic::getResolutionX() >= 800) // to prevent multiplying by 0
	{
		CoordinatesX.setCharacterSize(15 * (GameLogic::getResolutionX() / 800));
		CoordinatesY.setCharacterSize(15 * (GameLogic::getResolutionX() / 800));
	}
	else
	{
		CoordinatesX.setCharacterSize(12);
		CoordinatesY.setCharacterSize(12);
	}
}

void GUIpanel::updatePosition()
{
	positionX = player->getPositionX() - GameLogic::getResolutionX() / 2;
	positionY = player->getPositionY() - GameLogic::getResolutionY() / 2;
}

void GUIpanel::updatePanel()
{
	CoordinatesX.setString("X: " + to_string(static_cast<int>(player->getPositionX())));
	CoordinatesY.setString("Y: " + to_string(static_cast<int>(player->getPositionY())));

	CoordinatesX.setPosition(positionX + sizeX*0.10, positionY + sizeY*0.57);
	CoordinatesY.setPosition(positionX + sizeX*0.10, positionY + sizeY*0.64);

	speedDisplay.setPosition(positionX + sizeX*0.45, positionY + sizeY*0.55);
	speedDisplayDot.setPosition(
		speedDisplay.getPosition().x + (85*speedDisplay.getScale().x)/2 - (7*speedDisplayDot.getScale().x)/2
		+ (player->getActualSpeedX()/player->getMaxSpeed())*((65 * speedDisplay.getScale().x) / 2),

		speedDisplay.getPosition().y + (85*speedDisplay.getScale().y)/2 - (7*speedDisplayDot.getScale().y)/2 
		+ (player->getActualSpeedY() / player->getMaxSpeed())*((65 * speedDisplay.getScale().y) / 2)
		);
}

Text & GUIpanel::getCoordinatesX() { return CoordinatesX; }
Text & GUIpanel::getCoordinatesY() { return CoordinatesY; }
Sprite & GUIpanel::getSpeedDisplay() { return speedDisplay; }
Sprite & GUIpanel::getSpeedaDisplayDot() { return speedDisplayDot; }
