#pragma once

#include "DrawableObject.h"
#include <string>
using namespace std;

class Player : public DrawableObject
{

private:

	string playerName;

	//LOGIC OF THE PLAYER SHIP

	double actualHealth; // actual health
	double actualSpeedX;
	double actualSpeedY;
	double acceleration; // how fast can you gain more speed
	double rotationSpeed;

	bool isAlive;

	int maxHealth;		// maximal amount at the moment. You can raise it by upgrades
	double maxSpeed; // we are in space though :P
	// =======================

public:
	Player(string playerName, Texture & texture, double posX, double posY, double sizeX, double sizeY, double rotation);

	void gainHealth(int);
	void gainAcceleration(double);

	void move();
	void accelerate();
	void stop();
	void die();

	void looseHealth(int);		// Substracting values from the variables
	void looseAcceleration(double);
	
	double getRotationInRadians();
	double getRotationSpeed();
	double getActualSpeedX();
	double getActualSpeedY();
	double getMaxSpeed();
	bool getIfAlive();



	void rotateLeft();
	void rotateRight();

};