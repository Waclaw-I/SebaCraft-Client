#pragma once
#include "Bullet.h"

class MGunBullet : public Bullet
{
public:

	MGunBullet(double positionX, double positionY, double rotation);
	MGunBullet(double positionX, double positionY, double rotation, double speed, double duration, int damage, int playerID);

	~MGunBullet();


private:

};