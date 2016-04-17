#include "Player.h"
#include "TextureHolder.h"

#include <iostream>

Player::Player(std::string name, SpaceShip ship, int ID)
{
	this->ID = ID;
	this->name = name;
	this->ship = ship;
}

std::string Player::getName() { return this->name; }
SpaceShip & Player::getShip() { return this->ship; }
int Player::getID() { return this->ID; }

void Player::setName(std::string name) { this->name = name; }
void Player::setShip(SpaceShip ship) { this->ship = ship; }
void Player::setID(int ID) { this->ID = ID; }

void Player::updateGraphPosition()
{
	ship.getGraph().setPosition(ship.getPositionX(), ship.getPositionY());
	ship.getGraph().setRotation(ship.getRotation());
}

