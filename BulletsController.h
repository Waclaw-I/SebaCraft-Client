#pragma once
#include "Bullet.h"
#include <list>

class BulletsController
{
public:

	static BulletsController & getBulletsController();

	void addBullet(Bullet * bullet);
	void removeBullet(Bullet * bullet);
	//bool checkIfGone(Bullet * bullet);
	
	void controllBullets();

	std::list <Bullet *> & getBulletsInGame();

	
private:

	BulletsController();
	BulletsController(const BulletsController &);

	std::list <Bullet *> bulletsInGame;
	
	

	void moveBullets();
	void deleteDeadBullets();
};