#pragma once

class Point2D
{
private:
	int x;
	int y;

public:

	Point2D();
	Point2D(int x, int y);

	void setX(int x);
	void setY(int y);

	int getX();
	int getY();
};