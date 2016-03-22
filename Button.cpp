#include "Button.h"
#include "GraphMethods.h"

int Button::getHeight() { return height; }
int Button::getWidth() { return width; }
void Button::setHeight(int height) { this->height = height; }
void Button::setWidth(int width) { this->width = width; }

void Button::setPosition(int positionX, int positionY)
{
	this->positionX = positionX;
	this->positionY = positionY;

	activeSprite.setPosition(this->positionX, this->positionY);
	idleSprite.setPosition(this->positionX, this->positionY);
	hoveredSprite.setPosition(this->positionX, this->positionY);
	pressedSprite.setPosition(this->positionX, this->positionY);
}


Button::Button(string text, int width, int height, Color col, int fontSize)
{
	this->width = width;
	this->height = height;
	this->text.setString(text);
	this->text.setColor(col);
	this->text.setCharacterSize(fontSize);
}

Button::Button(int width, int height, Sprite sprite)
{
	this->width = width;
	this->height = height;
	this->activeSprite = sprite;
	this->idleSprite = sprite; //if there is no need for additional sprites

	GraphMethods::ScaleSprite(this->activeSprite, this->width, this->height);
	
}

Sprite Button::getSprite()
{
	return this->activeSprite;
}

void Button::setAdditionalSprites(Sprite idle, Sprite hovered, Sprite pressed) // if none, idle sprite will also be the active
{
	this->idleSprite = idle;
	this->hoveredSprite = hovered;
	this->pressedSprite = pressed;
}

void Button::activateIdleSprite() { activeSprite = idleSprite; }
void Button::activateHoveredSprite() { activeSprite = hoveredSprite; }
void Button::activatePressedSprite() { activeSprite = pressedSprite; }

