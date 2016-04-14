#include "UsefulMethods.h"

double UsefulMethods::getRotationInRadians(double rotation)
{
	return (rotation * (3.14 / 180));
}


SpaceShip * UsefulMethods::getSpaceShipType(int shipType)
{
	if (shipType == 1) return new SmallFighter();
	if (shipType == 2) return new Trasher();
	else return new SmallFighter();
}