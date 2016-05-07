#include "MGunBullet.h"
#include "TextureHolder.h"

MGunBullet::MGunBullet(double positionX, double positionY, double rotation):
	Bullet(3, 10, 2) // ( damage / speed / duration )
{
	this->positionX = positionX;
	this->positionY = positionY;
	this->rotation = rotation;

	this->graph.setTexture(TextureHolder::getBulletsTextures(0));
	this->graph.setOrigin(sizeX / 2, sizeY / 2);

	sizeX = 6; // width & height of bullet graph
	sizeY = 2;
}