#include "BulletsController.h"

BulletsController & BulletsController::getBulletsController()
{
	static BulletsController bulletsController;
	return bulletsController;
}

std::list <Bullet *> & BulletsController::getBulletsInGame()
{
	return this->bulletsInGame;
}

BulletsController::BulletsController() {}

void BulletsController::addBullet(Bullet * bullet)
{
	bulletsInGame.push_back(bullet);
}

void BulletsController::removeBullet(Bullet * bullet)
{
	bulletsInGame.remove(bullet);
}

//bool BulletsController::checkIfGone(Bullet * bullet)
//{
//	if (!bullet->isAlive())
//	{
//		delete; // returns true if ready to be deleted
//}

void BulletsController::moveBullets()
{
	for (Bullet * x : bulletsInGame)
	{
		x->move();
		x->decreaseDuration(); // by 0.016 <- 1/60 per frame, so duration = 2 equals ~2 seconds
		x->updateGraphPosition();
	}
}

void BulletsController::deleteDeadBullets()
{
	bulletsInGame.remove_if([](Bullet * x)->bool {if (!x->isAlive()) { delete x; return true; } return false; });
	
}

void BulletsController::controllBullets()
{
	moveBullets();
	deleteDeadBullets();
}