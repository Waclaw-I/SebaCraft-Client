#include "Trasher.h"
#include "TextureHolder.h"

#include <iostream>

Trasher::Trasher()
{
	actualHealth = 200;
	maxHealth = 200;
	actualEnergy = 150;
	maxEnergy = 150;
	actualArmour = 2;
	maxArmour = 2;
	actualSpeedX = 0;
	actualSpeedY = 0;
	acceleration = 0.05;

	sizeX = 92; // width of texture
	sizeY = 51; // height of texture
	maxSpeed = 1.5;

	rotation = 90;
	rotationSpeed = 2.5; // not as impressive as Small Fighter
	graph.setTexture(TextureHolder::getShipsTextures(1)); // texture of Trasher
	graph.setOrigin(sizeX / 2, sizeY / 2); // center of our texture

	leftMachineGun.setLocalPosition(38, -16);
	rightMachineGun.setLocalPosition(38, 17);

	setTurretsCooldown(0.5, 0.7);

}


void Trasher::setTurretsCooldown(double leftTurret, double rightTurret)
{
	leftMachineGun.setCooldown(leftTurret);
	rightMachineGun.setCooldown(rightTurret);
}

void Trasher::updateTurrets() // we are updating rotation and position of our turrets. It is needed to spawn bullets correctly
{
	leftMachineGun.setGlobalPosition(positionX, positionY);
	leftMachineGun.setRotation(rotation);
	leftMachineGun.reload();
	rightMachineGun.setGlobalPosition(positionX, positionY);
	rightMachineGun.setRotation(rotation);
	rightMachineGun.reload();

}


void Trasher::shoot()
{
	leftMachineGun.shoot();
	rightMachineGun.shoot();
}