#pragma once
#include "Bullet.h"
#include <list>

class BulletsController
{
public:

	static BulletsController & getBulletsController();

	std::list <Bullet *> & getBulletsInGame();
	void addBullet(Bullet *);
	void removeBullet(Bullet *);
private:

	BulletsController();
	BulletsController(const BulletsController &);

	std::list <Bullet *> bulletsInGame;
};