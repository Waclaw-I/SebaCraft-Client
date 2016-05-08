#pragma once
#include "SpaceShip.h"

class SmallFighter : public SpaceShip
{
private:

public:

	void updateTurrets() override;
	void shoot() override;

	SmallFighter();
};