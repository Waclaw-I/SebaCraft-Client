#pragma once
#include "SFML\Graphics.hpp"

static class GraphMethods
{
public:
	static void ScaleSprite(sf::Sprite & yourSprite, double targetX, double targetY);

	static void ScaleToResolution(sf::Sprite & yourSprite, double basicResX, double basicResY, double targetResX, double targetResY);
};