#pragma once

#include <SFML/Graphics.hpp>
#include "DrawableObject.h"
#include "Player.h"

#include <vector>

using namespace std;



class DisplayController
{
public:

	static vector <DrawableObject *>  ArrayOfDrawableObjects;

	void static InsertNewDrawableObject(DrawableObject *);

	//void static CheckIfDestroyed();

	void static UpdatePlayerGraph(Player *);



private:


};