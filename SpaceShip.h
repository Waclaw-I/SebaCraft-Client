#pragma once
#include "DrawableObject.h"

// all data about size, position, rotation and graphic are inherited from DrawableObject
class SpaceShip : public DrawableObject
{

public:

	int getActualHealth();
	int getActualEnergy();
	int getActualArmour();
	double getActualSpeedX();
	double getActualSpeedY();
	double getAcceleration();

	int getMaxHealth();
	int getMaxEnergy();
	int getMaxArmour();
	double getMaxSpeed();
	double getRotationSpeed();

	bool  isAlive();

	void setActualHealth(int actualHealth);
	void setActualEnergy(int actualEnergy);
	void setActualArmour(int actualArmour);
	void setActualSpeedX(double actualSpeedX);
	void setActualSpeedY(double actualSpeedY);
	void setAcceleration(double acceleration);

	void setMaxHealth(int maxHealth);
	void setMaxEnergy(int maxEnergy);
	void setMaxArmour(int maxArmour);
	void setMaxSpeed(double maxSpeed);

	void setAlive(bool alive);
	void setRotationSpeed(double rotationSpeed);

	SpaceShip(); // default constructor with values meaned to be changed later
	SpaceShip(double positionX, double positionY, Texture & texture, double sizeX, double sizeY, double rotation, // for DrawableObject constructor
		int health, int energy, int armour, int maxSpeed); // for SpaceShip variables



	void increaseHealth(int amount);
	void increaseEnergy(int amount);
	void increaseArmour(int amount);

	void decreaseHealth(int amount);
	void decreaseEnergy(int amount);
	void decreaseArmour(int amount); // with seting Alive on false if health falls to 0

	void accelerate();
	void stop();
	void move();
	void rotateLeft();
	void rotateRight();

	virtual void updateTurrets();
	virtual void shoot() = 0; // czysto wirtualna

protected:
	int actualHealth;
	int actualEnergy;
	int actualArmour;
	double actualSpeedX; 
	double actualSpeedY;
	double acceleration;

	int maxHealth;
	int maxEnergy;
	int maxArmour;
	double maxSpeed;

	bool alive;
	double rotationSpeed;



};