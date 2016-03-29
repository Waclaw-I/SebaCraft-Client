#include "Point2D.h"

Point2D::Point2D()
{
	this->x = 1;
	this->y = 1;
}

Point2D::Point2D(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Point2D::getX() { return this->x; }
int Point2D::getY() { return this->y; }

void Point2D::setX(int x) { this->x = x; }
void Point2D::setY(int y) { this->y = y; }