#pragma once
#include "DrawableObject.h"
#include "SpaceShip.h"
#include <string>

using namespace std;

class Player
{

private:

	std::string name;
	SpaceShip ship;
	

public:
	Player(std::string name, SpaceShip ship);

	std::string getName();
	SpaceShip & getShip();

	void setName(std::string name);
	void setShip(SpaceShip ship);

};