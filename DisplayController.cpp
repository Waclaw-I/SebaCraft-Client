#include "DisplayController.h"
#include <SFML/Graphics.hpp>

#include <iostream>
using namespace std;


vector <DrawableObject *>  DisplayController::ArrayOfDrawableObjects;

void DisplayController::InsertNewDrawableObject(DrawableObject * object)
{
	ArrayOfDrawableObjects.push_back(object);
}

void DisplayController::UpdatePlayerGraph(Player * player)
{
	double playerX = player->getShip().getPositionX();
	double playerY = player->getShip().getPositionY();
	double playerRotation = player->getShip().getRotation();

	player->getShip().getGraph().setPosition(playerX, playerY);
	player->getShip().getGraph().setRotation(playerRotation);

}

//void DisplayController::CheckIfDestroyed()
//{
//	for (int i = 0; i < ArrayOfDrawableObjects.size(); i++)
//	{
//		if (ArrayOfDrawableObjects[i]->GetMyGraph()->Get_isLogicAlive() == false)
//		{
//
//			delete ArrayOfDrawableObjects[i];
//			ArrayOfDrawableObjects.erase(ArrayOfDrawableObjects.begin() + i); // we just need to resize our array. Pointer is deleted in object destructor
//		}
//	}
//}