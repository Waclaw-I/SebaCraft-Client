#include "DrawableObject.h"


DrawableObject::DrawableObject(int windowX, int windowY, int globalX, int globalY, Texture & texture, int sizeX, int sizeY)
{
	this->windowPosition.setX(windowX);
	this->windowPosition.setY(windowY);
	this->globalPosition.setX(globalX);
	this->globalPosition.setY(globalY);
	this->graph.setTexture(texture);
	this->sizeX = sizeX;
	this->sizeY = sizeY;
}

Point2D DrawableObject::getWindowPosition() { return this->windowPosition; }
Point2D DrawableObject::getGlobalPosition() { return this->globalPosition; }
Sprite & DrawableObject::getGraph() { return this->graph; }

void DrawableObject::setWindowPosition(int x, int y) { windowPosition.setX(x); windowPosition.setY(y); }
void DrawableObject::setGlobalPosition(int x, int y) { globalPosition.setX(x); globalPosition.setY(y); }
void DrawableObject::setGraph(Sprite graph) { this->graph = graph; }