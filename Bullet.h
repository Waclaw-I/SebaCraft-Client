#pragma once

#include "DrawableObject.h"


class Bullet : public DrawableObject
{

public:

	Bullet(int damage, double speed, double duration);
	virtual ~Bullet(); // virtual destructor will asure that every destructor of child classes ll be executed

	virtual void move();
	double getDuration();
	bool isCollided();
	void decreaseDuration(double);

protected:

	int damage;
	double speed;
	double duration;
	bool collided;
};