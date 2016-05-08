#include "MGunBullet.h"
#include "TextureHolder.h"
#include "BulletsController.h"
#include "GameLogic.h"

#include <iostream>
using namespace std;

MGunBullet::MGunBullet(double positionX, double positionY, double rotation): // BULLET FROM THIS CLIENT
	Bullet(3, 10, 2) // ( damage / speed / duration )
{
	this->positionX = positionX;
	this->positionY = positionY;
	this->rotation = rotation;

	this->graph.setTexture(TextureHolder::getBulletsTextures(0));
	

	sizeX = 6; // width & height of bullet graph
	sizeY = 2;

	this->allied = true;

	this->graph.setOrigin((float)(sizeX / 2), (float)(sizeY / 2));

	BulletsController::getBulletsController().addBullet(this);
	GameLogic::sendMGunBulletToServer(this);

}

MGunBullet::MGunBullet(double positionX, double positionY, double rotation, double speed, double duration, int damage) // BULLET FROM SERVER
	: Bullet(damage, speed, duration)
{
	this->positionX = positionX;
	this->positionY = positionY;
	this->rotation = rotation;

	this->allied = false;

	this->graph.setTexture(TextureHolder::getBulletsTextures(1));


	sizeX = 6; // width & height of bullet graph
	sizeY = 2;

	this->graph.setOrigin((float)(sizeX / 2), (float)(sizeY / 2));

	BulletsController::getBulletsController().addBullet(this);
}

MGunBullet::~MGunBullet() {}