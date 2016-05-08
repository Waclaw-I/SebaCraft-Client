#include "SmallFighter.h"
#include "TextureHolder.h"

SmallFighter::SmallFighter()
{
	actualHealth = 100;
	maxHealth = 100;
	actualEnergy = 100;
	maxEnergy = 100;
	actualArmour = 1;
	maxArmour = 1;
	actualSpeedX = 0;
	actualSpeedY = 0;
	acceleration = 0.1;

	sizeX = 61; // width of texture
	sizeY = 51; // height of texture
	maxSpeed = 2;

	rotation = 90;
	rotationSpeed = 3; // it can turn pretty damn fast!
	graph.setTexture(TextureHolder::getShipsTextures(0)); // texture of Small Fighter
	graph.setOrigin(sizeX / 2, sizeY / 2); // center of our texture

	leftMachineGun.setLocalPosition(32, 10);
	rightMachineGun.setLocalPosition(32, -10);

	setTurretsCooldown(0.4, 0.4);
}

void SmallFighter::setTurretsCooldown(double leftTurret, double rightTurret)
{
	leftMachineGun.setCooldown(leftTurret);
	rightMachineGun.setCooldown(rightTurret);
}
void SmallFighter::updateTurrets() 
{
	leftMachineGun.setGlobalPosition(positionX, positionY);
	leftMachineGun.setRotation(rotation);
	leftMachineGun.reload();
	rightMachineGun.setGlobalPosition(positionX, positionY);
	rightMachineGun.setRotation(rotation);
	rightMachineGun.reload();
}
void SmallFighter::shoot()
{
	leftMachineGun.shoot();
	rightMachineGun.shoot();
}