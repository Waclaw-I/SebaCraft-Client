#include "SpaceShip.h"
#include <cstdlib>

#include <iostream>

// GETTERS AND SETTERS
int SpaceShip::getActualHealth() { return this->actualHealth; }
int SpaceShip::getActualEnergy() { return this->actualEnergy; }
int SpaceShip::getActualArmour() { return this->actualArmour; }
double SpaceShip::getActualSpeedX() { return this->actualSpeedX; }
double SpaceShip::getActualSpeedY() { return this->actualSpeedY; }
double SpaceShip::getAcceleration() { return this->acceleration; }

int SpaceShip::getMaxHealth() { return this->maxHealth; }
int SpaceShip::getMaxEnergy() { return this->maxEnergy; }
int SpaceShip::getMaxArmour() { return this->maxArmour; }
double SpaceShip::getMaxSpeed() { return this->maxSpeed; }

bool SpaceShip::isAlive() { return this->alive; }
double SpaceShip::getRotationSpeed() { return this->rotationSpeed; }

void SpaceShip::setActualHealth(int actualHealth) { this->actualHealth = actualHealth; }
void SpaceShip::setActualEnergy(int actualEnergy) { this->actualEnergy = actualEnergy; }
void SpaceShip::setActualArmour(int actualArmour) { this->actualArmour = actualArmour; }
void SpaceShip::setActualSpeedX(double actualSpeedX) { this->actualSpeedX = actualSpeedX; }
void SpaceShip::setActualSpeedY(double actualSpeedY) { this->actualSpeedY = actualSpeedY; }
void SpaceShip::setAcceleration(double acceleration) { this->acceleration = acceleration; }

void SpaceShip::setMaxHealth(int maxHealth) { this->maxHealth = maxHealth; }
void SpaceShip::setMaxEnergy(int maxEnergy) { this->maxEnergy = maxEnergy; }
void SpaceShip::setMaxArmour(int maxArmour) { this->maxArmour = maxArmour; }
void SpaceShip::setMaxSpeed(double maxSpeed) { this->maxSpeed = maxSpeed; }

void SpaceShip::setAlive(bool alive) { this->alive = alive; }
void SpaceShip::setRotationSpeed(double rotationSpeed) { this->rotationSpeed = rotationSpeed; }

// CONSTRUCTORS

SpaceShip::SpaceShip(double positionX, double positionY, Texture & texture, double sizeX, double sizeY, double rotation, // for DrawableObject constructor
	int health, int energy, int armour, int maxSpeed) : DrawableObject(positionX, positionY, texture, sizeX, sizeY, rotation)
{
	this->actualHealth = health;
	this->maxHealth = health;
	this->actualEnergy = energy;
	this->maxEnergy = energy;
	this->actualArmour = armour;
	this->maxArmour = armour;
	this->actualSpeedX = 0;
	this->actualSpeedY = 0;
	this->maxSpeed = maxSpeed;
}

SpaceShip::SpaceShip()
{
	this->actualHealth = 100;
	this->maxHealth = 100;
	this->actualEnergy = 100;
	this->maxEnergy = 100;
	this->actualArmour = 1;
	this->maxArmour = 1;
	this->actualSpeedX = 0;
	this->actualSpeedY = 0;
	this->maxSpeed = 2;

	this->positionX = rand() % 1000;
	this->positionY = rand() % 1000;
	this->alive = true;
}

// OTHER METHODS

void SpaceShip::increaseHealth(int amount)
{ 
	this->actualHealth += amount;
	if (actualHealth > maxHealth) actualHealth = maxHealth;
}

void SpaceShip::increaseEnergy(int amount)
{
	this->actualEnergy += amount;
	if (actualEnergy > maxEnergy) actualEnergy = maxEnergy;
}
void SpaceShip::increaseArmour(int amount)
{
	this->actualArmour += amount;
	if (actualArmour > maxArmour) actualArmour = maxArmour;
}

void SpaceShip::decreaseHealth(int amount)
{
	this->actualHealth -= amount;
	if (actualHealth <= 0)
	{
		actualHealth = 0;
		setAlive(false); // ship got destroyed
	}
}
void SpaceShip::decreaseEnergy(int amount)
{
	this->actualEnergy -= amount;
	if (actualEnergy <= 0) actualEnergy = 0;
}

void SpaceShip::decreaseArmour(int amount)
{
	this->actualArmour -= amount; // we can decrease armour below 0. Need to think about that later, when armour ll actually be a thing in the game
}


void SpaceShip::accelerate()
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

void SpaceShip::stop()
{
	if (actualSpeedX > 0)
	{
		actualSpeedX -= acceleration / 2;
		if (actualSpeedX < 0.001) actualSpeedX = 0;
	}
	if (actualSpeedY > 0)
	{
		actualSpeedY -= acceleration / 2;
		if (actualSpeedY < 0.001) actualSpeedY = 0;
	}
	if (actualSpeedX < 0)
	{
		actualSpeedX += acceleration / 2;
		if (actualSpeedX > -0.001) actualSpeedX = 0;
	}
	if (actualSpeedY < 0)
	{
		actualSpeedY += acceleration / 2;
		if (actualSpeedY > -0.001) actualSpeedY = 0;
	}

	updateTurrets();
}

void SpaceShip::move()
{
	positionX += actualSpeedX;
	positionY += actualSpeedY;
	updateTurrets();
}

void SpaceShip::rotateLeft()
{
	if (rotation < 0.1) rotation = 360;
	rotation -= rotationSpeed;
	updateTurrets();
}

void SpaceShip::rotateRight()
{
	if (rotation > 359.9) rotation = 0;
	rotation += rotationSpeed;
	updateTurrets();
}

void SpaceShip::updateTurrets() {}
void SpaceShip::shoot() { }