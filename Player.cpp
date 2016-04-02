#include "Player.h"
#include "TextureHolder.h"

#include <iostream>

Player::Player(string playerName, Texture & texture, double posX, double posY, double sizeX, double sizeY, double rotation)
	: DrawableObject(posX, posY, texture, sizeX, sizeY, 0)
{
	this->playerName = playerName;
	this->actualHealth = 100;
	this->actualSpeedX = 0;
	this->actualSpeedY = 0;
	this->acceleration = 0.1;
	this->maxHealth = 100;
	this->maxSpeed = 2.5;
	this->rotationSpeed = 2.5;
	this->isAlive = true;

	this->getGraph().setOrigin(this->sizeX / 2, this->sizeY / 2); // axis of rotation is at the center
}


double Player::getRotationInRadians()
{
	return (rotation * (3.14 / 180));
}

double Player::getRotationSpeed() { return rotationSpeed; }

double Player::getActualSpeedX() { return actualSpeedX; }
double Player::getActualSpeedY() { return actualSpeedY; }
double Player::getMaxSpeed() { return maxSpeed; }

bool Player::getIfAlive() { return isAlive; }

void Player::gainHealth(int amount) { if (actualHealth < maxHealth) actualHealth += amount; }

void Player::gainAcceleration(double amount) { acceleration += amount; }

void Player::looseHealth(int amount)
{
	actualHealth -= amount;
	if (actualHealth <= 0) die();
}

void Player::die() { isAlive = false; }

void Player::accelerate()
{

	if ((rotation >= 0) && (rotation <= 90))					// +/+ quarter
	{
		if (actualSpeedX < maxSpeed)	actualSpeedX += acceleration *((90 - rotation) / 90);
		if (actualSpeedY < maxSpeed)	actualSpeedY += acceleration*(rotation / 90);
	}
	if ((rotation >= 90) && (rotation <= 180))					// +/- quarter
	{
		if (actualSpeedX > -maxSpeed)	actualSpeedX -= acceleration *((rotation - 90) / 90);
		if (actualSpeedY < maxSpeed)	actualSpeedY += acceleration*((180 - rotation) / 90);
	}
	if ((rotation >= 180) && (rotation <= 270))					// -/- quarter
	{
		if (actualSpeedX > -maxSpeed)	actualSpeedX -= acceleration *((270 - rotation) / 90);
		if (actualSpeedY > -maxSpeed)	actualSpeedY -= acceleration *((rotation - 180) / 90);
	}
	if ((rotation >= 270) && (rotation <= 360))					// -/+ quarter
	{
		if (actualSpeedX < maxSpeed)	actualSpeedX += acceleration *((rotation - 270) / 90);
		if (actualSpeedY > -maxSpeed)	actualSpeedY -= acceleration *((360 - rotation) / 90);
	}
}

void Player::stop()
{
	if (actualSpeedX > 0)
	{
		actualSpeedX -= acceleration/2;
		if (actualSpeedX < 0.001) actualSpeedX = 0;
	}
	if (actualSpeedY > 0)
	{
		actualSpeedY -= acceleration/2;
		if (actualSpeedY < 0.001) actualSpeedY = 0;
	}
	if (actualSpeedX < 0)
	{
		actualSpeedX += acceleration/2;
		if (actualSpeedX > -0.001) actualSpeedX = 0;
	}
	if (actualSpeedY < 0)
	{
		actualSpeedY += acceleration/2;
		if (actualSpeedY > -0.001) actualSpeedY = 0;
	}
}

void Player::looseAcceleration(double amount)
{
	acceleration -= amount;
}

void Player::rotateLeft()
{
	if (rotation < 0.1) rotation = 360;
	rotation -= rotationSpeed;
}

void Player::rotateRight()
{
	if (rotation > 359.9) rotation = 0;
	rotation += rotationSpeed;
}

void Player::move()
{
	positionX += actualSpeedX;
	positionY += actualSpeedY;
}
