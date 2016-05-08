#include "MachineGun.h"
#include <math.h>
#include "MathMethods.h"
#include "MGunBullet.h"
#include <iostream>

MachineGun::MachineGun()
{
	this->cooldown = 0.5;
	timer = 0;
	readyToShoot = false;
}

void MachineGun::setLocalPositionX(int x) { this->localPositionX = x; }
void MachineGun::setLocalPositionY(int y) { this->localPositionY = y; }

void MachineGun::setLocalPosition(int x, int y)
{
	this->localPositionX = x;
	this->localPositionY = y;
}

void MachineGun::setGlobalPositionX(int x) { this->globalPositionX = x; }
void MachineGun::setGlobalPositionY(int y) { this->globalPositionY = y; }

void MachineGun::setGlobalPosition(int x, int y)
{
	this->globalPositionX = x;
	this->globalPositionY = y;
}

void MachineGun::setRotation(double rotation) { this->rotation = rotation; }


int MachineGun::getLocalPositionX() { return localPositionX; }
int MachineGun::getLocalPositionY() { return localPositionY; }

int MachineGun::getGlobalPositionX() { return globalPositionX; }
int MachineGun::getGlobalPositionY() { return globalPositionY; }

void MachineGun::calculateSpawnPoint()
{
	double radians = MathMethods::getMathMethods().degToRad(rotation);
	bulletSpawnPositionX = globalPositionX + (localPositionX * cos(radians) - localPositionY * sin(radians));
	bulletSpawnPositionY = globalPositionY + (localPositionX * sin(radians) + localPositionY * cos(radians));
}

double MachineGun::getCooldown() { return this->cooldown; }
double MachineGun::getTimer() { return this->cooldown; }
bool MachineGun::isReadyToShoot() { return this->readyToShoot; }

void MachineGun::setTimer(double timer) { this->timer = timer; }
void MachineGun::setCooldown(double cooldown) { this->cooldown = cooldown; }
void MachineGun::setReadyToShoot(bool readyToShoot) { this->readyToShoot = readyToShoot; }

void MachineGun::reload()
{
	if (readyToShoot == false)
	{
		if (timer > cooldown)
		{
			timer = 0;
			readyToShoot = true;
		}
		else timer += 0.016;
	}
}
void MachineGun::shoot()
{
	if (readyToShoot)
	{
		calculateSpawnPoint();
		MGunBullet * mGunBullet = new MGunBullet(bulletSpawnPositionX, bulletSpawnPositionY, rotation);
		readyToShoot = false;
	}
}