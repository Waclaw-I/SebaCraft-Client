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
	double playerX = player->getGlobalPositionX();
	double playerY = player->getGlobalPositionY();
	double playerRotation = player->getRotation();

	player->getGraph().setPosition(playerX, playerY);
	player->getGraph().setRotation(playerRotation);

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