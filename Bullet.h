#pragma once

#include "DrawableObject.h"


class Bullet : public DrawableObject
{

public:

	Bullet(int damage, double speed, double duration);
	virtual ~Bullet(); // virtual destructor will asure that every destructor of child classes ll be executed

	virtual void move();
	double getDuration();
	double getSpeed();
	int getDamage();
	bool isCollided();
	void decreaseDuration();
	bool isAlive();
	void setAlive(bool alive);
	bool isAllied();
	void setAllied(bool allied);

protected:

	bool allied;
	int damage;
	double speed;
	double duration;
	bool collided;
	bool alive;
};