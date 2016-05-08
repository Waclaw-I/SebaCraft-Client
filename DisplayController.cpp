#include "DisplayController.h"
#include <SFML/Graphics.hpp>

#include <iostream>
using namespace std;


vector <DrawableObject *>  DisplayController::ArrayOfDrawableObjects;

void DisplayController::InsertNewDrawableObject(DrawableObject * object)
{
	ArrayOfDrawableObjects.push_back(object);
}
