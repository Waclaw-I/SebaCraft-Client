#include "Bullet.h"

#include <iostream>
#include <cstdlib>

using namespace std;

Bullet::Bullet(int damage, double speed, double duration)
{
	this->damage = damage;
	this->speed = speed;
	this->duration = duration;
	this->alive = true;
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
	if ((rotation >= 270) && (rotation <= 360))					// -/+ quarter
	{
		positionX += speed *((rotation - 270) / 90);
		positionY -= speed *((360 - rotation) / 90);
	}
}
bool Bullet::isCollided() { return this->collided; }
bool Bullet::isAlive() { return this->alive; }
void Bullet::setAlive(bool alive) { this->alive = alive; }
bool Bullet::isAllied() { return this->allied; }
void Bullet::setAllied(bool allied) { this->allied = allied; }

double Bullet::getDuration() { return this->duration; }
double Bullet::getSpeed() { return this->speed; }
int Bullet::getDamage() { return this->damage; }

void Bullet::decreaseDuration()
{
	duration -= 0.016;
	if (duration <= 0) alive = false;
}