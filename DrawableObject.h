#pragma once

#include "SFML\Graphics.hpp"

using namespace sf;

class DrawableObject
{
protected:
	double windowPositionX;
	double windowPositionY;
	double globalPositionX;
	double globalPositionY;
	double sizeX;
	double sizeY;
	double rotation;
	Sprite graph;

public:

	DrawableObject(double windowX, double windowY, double globalX, double globalY, Texture & texture, double sizeX, double sizeY, double rotation);

	double getWindowPositionX();
	double getWindowPositionY();
	double getGlobalPositionX();
	double getGlobalPositionY();

	Sprite & getGraph();
	double getSizeX();
	double getSizeY();
	double getRotation();

	void setWindowPositionX(double x);
	void setWindowPositionY(double y);
	void setGlobalPositionX(double x);
	void setGlobalPositionY(double y);

	void setGraph(Sprite graph);
	void setSizeX(double x);
	void setSizeY(double y);
	void setRotation(double rotation);
};