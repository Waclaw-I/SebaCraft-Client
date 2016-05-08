#include "Bullet.h"
#include "GameLogic.h"

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

bool Bullet::checkCollisionForThisClient(Player * player)
{
	if (!isAllied())
	{
		double startX = player->getShip()->getPositionX() - (player->getShip()->getSizeX() / 2);
		double endX = startX + player->getShip()->getSizeX();
		double startY = player->getShip()->getPositionY() - (player->getShip()->getSizeY() / 2);
		double endY = startY + player->getShip()->getSizeY();

		if ((positionX >= startX) && (positionX <= endX))
			if ((positionY >= startY) && (positionY <= endY))
			{
				return true;
			}
	}
	return false;
}

bool Bullet::checkCollisionForOthers()
{
	for (Player * player : GameLogic::getPlayersList())
	{
		if (playerID != player->getID())
		{
			double startX = player->getShip()->getPositionX() - (player->getShip()->getSizeX() / 2);
			double endX = startX + player->getShip()->getSizeX();
			double startY = player->getShip()->getPositionY() - (player->getShip()->getSizeY() / 2);
			double endY = startY + player->getShip()->getSizeY();

			if ((positionX >= startX) && (positionX <= endX))
				if ((positionY >= startY) && (positionY <= endY))
				{
					return true;
				}
		}
	}
	return false;
}

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
void Bullet::setPlayerID(int ID) { this->playerID = ID; } // for bullets gained from server

double Bullet::getDuration() { return this->duration; }
double Bullet::getSpeed() { return this->speed; }
int Bullet::getDamage() { return this->damage; }
int Bullet::getPlayerID() { return this->playerID; }

void Bullet::decreaseDuration()
{
	duration -= 0.016;
	if (duration <= 0) alive = false;
}