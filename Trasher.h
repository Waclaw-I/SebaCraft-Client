#pragma once
#include "SpaceShip.h"
#include "MachineGun.h"

class Trasher : public SpaceShip
{
public:
	Trasher();

private:
	MachineGun leftMachineGun;
	MachineGun rightMachineGun;
};