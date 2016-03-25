#include "Button.h"
#include "GraphMethods.h"

int Button::getHeight() { return height; }
int Button::getWidth() { return width; }
int Button::getPositionX() { return positionX; }
int Button::getPositionY() { return positionY; }
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

Button::Button(int width, int height, Texture & idle, Texture & hovered, Texture & pressed)
{
	this->width = width;
	this->height = height;
	this->idleSprite.setTexture(idle); //if there is no need for additional sprites
	this->activeSprite = idleSprite;

	this->hoveredSprite.setTexture(hovered);
	this->pressedSprite.setTexture(pressed);

	GraphMethods::ScaleSprite(this->activeSprite, this->width, this->height); // we need to scale sprite in order to fill up button 
	GraphMethods::ScaleSprite(this->idleSprite, this->width, this->height);
	GraphMethods::ScaleSprite(this->hoveredSprite, this->width, this->height);
	
}

Sprite & Button::getSprite()
{
	return this->activeSprite;
}


void Button::activateIdleSprite() { activeSprite = idleSprite; }
void Button::activateHoveredSprite() { activeSprite = hoveredSprite; }
void Button::activatePressedSprite() { activeSprite = pressedSprite; }

bool Button::isMouseOver(Window & window)
{
	if (Mouse::getPosition(window).x > positionX && Mouse::getPosition(window).x < positionX + width)
		if (Mouse::getPosition(window).y > positionY && Mouse::getPosition(window).y < positionY + height)
			return true;
		else return false;
	else return false;
}

bool Button::isButtonPressed(Window & window)
{
	if (isMouseOver(window) && Mouse::isButtonPressed(Mouse::Left)) return true;
	else return false;
}

void Button::changeVisibleSprite(Window & window)
{
	if (isMouseOver(window)) activateHoveredSprite();
	else activateIdleSprite();
	if (isButtonPressed(window)) activatePressedSprite();
}

