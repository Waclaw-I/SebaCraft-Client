#include "DrawableObject.h"


DrawableObject::DrawableObject(double positionX, double positionY, Texture & texture, double sizeX, double sizeY, double rotation)
{
	this->positionX = positionX;
	this->positionY = positionY;
	this->graph.setTexture(texture);
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->rotation = rotation;
}

double DrawableObject::getPositionX() { return this->positionX; }
double DrawableObject::getPositionY() { return this->positionY; }

Sprite & DrawableObject::getGraph() { return this->graph; }
double DrawableObject::getSizeX() { return this->sizeX; }
double DrawableObject::getSizeY() { return this->sizeY; }
double DrawableObject::getRotation() { return this->rotation; }

void DrawableObject::setPositionX(double x) { this->positionX = x; }
void DrawableObject::setPositionY(double y) { this->positionY = y; }

void DrawableObject::setGraph(Sprite graph) { this->graph = graph; }
void DrawableObject::setSizeX(double x) { this->sizeX = x; }
void DrawableObject::setSizeY(double y) { this->sizeY = y; }
void DrawableObject::setRotation(double rotation) { this->rotation = rotation; }