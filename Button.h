#pragma once

#include <SFML\Graphics.hpp>;
#include <iostream>

using namespace std;
using namespace sf;

class Button
{
private:
	int width;
	int height;

	int positionX;
	int positionY;

	Text text;

	Sprite activeSprite; // currently active sprite

	Sprite idleSprite; // if nothing happens
	Sprite pressedSprite; // if button was pressed
	Sprite hoveredSprite; // is mouse is over the button


public:

	Button(string text, int width, int height, Color col, int fontSize); // use Text to create button
	Button(int width, int height, Sprite sprite); // create button using graphic

	int getWidth(); // get width of the button
	int getHeight(); // get height of the button
	void setWidth(int width); // set width of the button
	void setHeight(int height); // set height of the button
	void setPosition(int positionX, int positionY); // set global position of the button

	Sprite getSprite(); // get actual Sprite of the button (if is avaiable)

	void setAdditionalSprites(Sprite idle, Sprite hovered, Sprite pressed); // set sprites foridle, hovered and pressed stances of the button

	void activateIdleSprite(); // we can decide, which sprite is currently active
	void activateHoveredSprite();
	void activatePressedSprite();
};