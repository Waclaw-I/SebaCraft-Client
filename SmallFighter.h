#pragma once
#include "SpaceShip.h"
#include "MachineGun.h"

class SmallFighter : public SpaceShip
{

public:

	void updateTurrets() override;
	void setTurretsCooldown(double leftTurret, double rightTurret);
	void shoot() override;

	SmallFighter();

private:
	MachineGun leftMachineGun;
	MachineGun rightMachineGun;

};