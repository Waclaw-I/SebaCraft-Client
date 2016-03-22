#include "GraphMethods.h"

void GraphMethods::ScaleSprite(sf::Sprite& yourSprite, double targetX, double targetY)
{
	yourSprite.setScale(
		targetX / yourSprite.getLocalBounds().width,
		targetY / yourSprite.getLocalBounds().height);
}