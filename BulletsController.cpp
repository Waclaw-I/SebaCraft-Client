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

void BulletsController::addBullet(Bullet *)
{

}

void BulletsController::removeBullet(Bullet *)
{

}