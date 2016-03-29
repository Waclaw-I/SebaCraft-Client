#pragma once

#include "DrawableObject.h"
#include <string>
using namespace std;

class Player : public DrawableObject
{

private:

	string playerName;

	//LOGIC OF THE PLAYER SHIP
	int sizeX;
	int sizeY;

	double actualHealth; // actual health
	double actualSpeedX;
	double actualSpeedY;
	double acceleration; // how fast can you gain more speed
	double rotationSpeed;

	bool isAlive;

	int maxHealth;		// maximal amount at the moment. You can raise it by upgrades
	double maxSpeed; // we are in space though :P

	double x; // position and rotation
	double y;
	double rotation;
	// =======================

public:
	Player(string playerName);

	void gainHealth(int);
	void gainAcceleration(double);

	void move();
	void accelerate();
	void stop();
	void die();

	void looseHealth(int);		// Substracting values from the variables
	void looseAcceleration(double);
	

	double getPositionX();				// methods for returning position to Displayer class
	double getPositionY();
	int getSizeX();
	int getSizeY();
	double getRotation();
	double getRotationInRadians();
	double getRotationSpeed();
	double getActualSpeedX();
	double getActualSpeedY();
	bool getIfAlive();



	void rotateLeft();
	void rotateRight();

};