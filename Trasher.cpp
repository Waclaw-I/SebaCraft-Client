#include "Trasher.h"
#include "TextureHolder.h"


Trasher::Trasher()
{
	positionX = 300;
	positionY = 300;
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

	leftMachineGun.setX(38); // spawn points for this specific ship
	leftMachineGun.setY(-16); // used to spawn bullets
	rightMachineGun.setX(38);
	rightMachineGun.setY(17); // if this class grows, I ll consider making some sort of initialization method
}