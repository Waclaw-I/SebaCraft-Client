#pragma once
#include "SpaceShip.h"
#include "MachineGun.h"

class Trasher : public SpaceShip
{
public:
	Trasher();

	void updateTurrets() override;
	void setTurretsCooldown(double leftTurret, double rightTurret);
	void shoot() override;


private:
	MachineGun leftMachineGun;
	MachineGun rightMachineGun;
};