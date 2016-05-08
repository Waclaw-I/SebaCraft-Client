#include "UsefulMethods.h"



SpaceShip * UsefulMethods::getSpaceShipType(int shipType)
{
	if (shipType == 1) return new SmallFighter();
	if (shipType == 2) return new Trasher();
	else return new SmallFighter();
}