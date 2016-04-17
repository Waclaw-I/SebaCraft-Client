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
	int ID;
	

public:
	Player(std::string name, SpaceShip ship, int ID);

	std::string getName();
	SpaceShip & getShip();
	int getID();

	void setName(std::string name);
	void setShip(SpaceShip ship);
	void setID(int ID);

	void updateGraphPosition();

};