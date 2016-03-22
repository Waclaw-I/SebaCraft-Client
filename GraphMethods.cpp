#include "GraphMethods.h"

#include <iostream>


void GraphMethods::ScaleSprite(sf::Sprite & yourSprite, double targetX, double targetY)
{
	yourSprite.setScale(
		targetX / yourSprite.getLocalBounds().width,
		targetY / yourSprite.getLocalBounds().height);
	std::cout << yourSprite.getScale().x << "	" << yourSprite.getScale().y << std::endl;
}