#include "Bullet.h"
#include "BulletsController.h"

#include <iostream>
#include <cstdlib>

using namespace std;

Bullet::Bullet(int damage, double speed, double duration)
{
	this->damage = damage;
	this->speed = speed;
	this->duration = duration;

	BulletsController::getBulletsController().addBullet(this);
}

Bullet::~Bullet()
{
	BulletsController::getBulletsController().removeBullet(this);
}


Bullet::~Bullet() {}

void Bullet::move()
{
	if ((rotation >= 0) && (rotation < 90))					// +/+ quarter
	{
		positionX += speed *((90 - rotation) / 90);
		positionY += speed *(rotation / 90);
	}
	if ((rotation >= 90) && (rotation < 180))					// +/- quarter
	{
		positionX -= speed *((rotation - 90) / 90);
		positionY += speed *((180 - rotation) / 90);
	}
	if ((rotation >= 180) && (rotation < 270))					// -/- quarter
	{
		positionX -= speed *((270 - rotation) / 90);
		positionY -= speed *((rotation - 180) / 90);
	}
	if ((rotation >= 270) && (rotation < 360))					// -/+ quarter
	{
		positionX += speed *((rotation - 270) / 90);
		positionY -= speed *((360 - rotation) / 90);
	}
}
bool Bullet::isCollided() { return collided; }

double Bullet::getDuration() { return duration; }

void Bullet::decreaseDuration(double amount) { duration -= amount; }