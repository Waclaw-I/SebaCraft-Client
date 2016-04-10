#pragma once

#include "SFML\Graphics.hpp"

using namespace sf;

class DrawableObject
{
protected:
	double positionX;
	double positionY;
	double sizeX;
	double sizeY;
	double rotation;
	Sprite graph;

public:

	DrawableObject(double positionX, double positionY, Texture & texture, double sizeX, double sizeY, double rotation);
	DrawableObject();

	double getPositionX();
	double getPositionY();

	Sprite & getGraph();
	double getSizeX();
	double getSizeY();
	double getRotation();

	void setPositionX(double x);
	void setPositionY(double y);

	void setGraph(Sprite graph);
	void setSizeX(double x);
	void setSizeY(double y);
	void setRotation(double rotation);
};