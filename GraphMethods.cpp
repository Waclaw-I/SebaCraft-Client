#include "GraphMethods.h"

#include <iostream>


void GraphMethods::ScaleSprite(sf::Sprite & yourSprite, double targetX, double targetY)
{
	yourSprite.setScale(
		targetX / yourSprite.getLocalBounds().width,
		targetY / yourSprite.getLocalBounds().height);
}

void GraphMethods::ScaleToResolution(sf::Sprite & yourSprite, double basicResX, double basicResY, double targetResX, double targetResY)
{
	yourSprite.setScale(
		targetResX / basicResX,
		targetResY / basicResY);
}