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

void BulletsController::lookForCollisions(Player * player)
{
	for (Bullet * x : bulletsInGame)
	if (x->checkCollisionForThisClient(player))
	{
		player->getShip()->decreaseHealth(x->getDamage());
		x->setAlive(false);
		continue;
	}
	else if (x->checkCollisionForOthers()) x->setAlive(false);
}

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