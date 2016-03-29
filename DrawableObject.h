#pragma once

#include "SFML\Graphics.hpp"
#include "Point2D.h"

using namespace sf;

class DrawableObject
{
protected:
	Point2D windowPosition;
	Point2D globalPosition;
	int sizeX;
	int sizeY;
	Sprite graph;

public:

	DrawableObject(int windowX, int windowY, int globalX, int globalY, Texture & texture, int sizeX, int sizeY);

	Point2D getWindowPosition();
	Point2D getGlobalPosition();
	Sprite & getGraph();

	void setWindowPosition(int x, int y);
	void setGlobalPosition(int x, int y);
	void setGraph(Sprite graph);
};