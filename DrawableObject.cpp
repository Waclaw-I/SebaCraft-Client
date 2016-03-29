#include "DrawableObject.h"


DrawableObject::DrawableObject(double windowX, double windowY, double globalX, double globalY, Texture & texture, double sizeX, double sizeY, double rotation)
{
	this->windowPositionX = windowX;
	this->windowPositionY = windowY;
	this->globalPositionX = globalX;
	this->globalPositionY = globalY;
	this->graph.setTexture(texture);
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->rotation = rotation;
}

double DrawableObject::getWindowPositionX() { return this->windowPositionX; }
double DrawableObject::getWindowPositionY() { return this->windowPositionY; }
double DrawableObject::getGlobalPositionX() { return this->globalPositionX; }
double DrawableObject::getGlobalPositionY() { return this->globalPositionY; }

Sprite & DrawableObject::getGraph() { return this->graph; }
double DrawableObject::getSizeX() { return this->sizeX; }
double DrawableObject::getSizeY() { return this->sizeY; }
double DrawableObject::getRotation() { return this->rotation; }

void DrawableObject::setWindowPositionX(double x) { this->windowPositionX = x; }
void DrawableObject::setWindowPositionY(double y) { this->windowPositionX = y; }
void DrawableObject::setGlobalPositionX(double x) { this->windowPositionX = x; }
void DrawableObject::setGlobalPositionY(double y) { this->windowPositionX = y; }

void DrawableObject::setGraph(Sprite graph) { this->graph = graph; }
void DrawableObject::setSizeX(double x) { this->sizeX = x; }
void DrawableObject::setSizeY(double y) { this->sizeY = y; }
void DrawableObject::setRotation(double rotation) { this->rotation = rotation; }