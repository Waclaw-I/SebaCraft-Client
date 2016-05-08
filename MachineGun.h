#pragma once

class MachineGun // this one should be abstract with name "Turret"
{
public:

	MachineGun();

	int getLocalPositionX();
	int getLocalPositionY();

	void setLocalPositionX(int);
	void setLocalPositionY(int);

	void setLocalPosition(int x, int y);
	void setGlobalPosition(int x, int y);

	int getGlobalPositionX();
	int getGlobalPositionY();

	void setGlobalPositionX(int);
	void setGlobalPositionY(int);

	void setRotation(double rotation);

	void calculateSpawnPoint();

	void setTimer(double timer);
	void setCooldown(double cooldown);
	void setReadyToShoot(bool readyToShoot);

	void reload();

	double getTimer();
	double getCooldown();
	bool isReadyToShoot();

	void shoot();

private:

	int localPositionX;
	int localPositionY; // relative to the ship

	int globalPositionX; // relative to the global
	int globalPositionY;

	int bulletSpawnPositionX; // this one includes rotation of the ship
	int bulletSpawnPositionY;

	double rotation; // this need to be updated in ship's class

	// SHOOTING VARIABLES
	double cooldown;
	double timer;
	bool readyToShoot;

};