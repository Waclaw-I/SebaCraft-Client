#include "Player.h"
#include "TextureHolder.h"

#include <iostream>

Player::Player(std::string name, SpaceShip ship)
{
	this->name = name;
	this->ship = ship;
}

std::string Player::getName() { return this->name; }
SpaceShip & Player::getShip() { return this->ship; }

void Player::setName(std::string name) { this->name = name; }
void Player::setShip(SpaceShip ship) { this->ship = ship; }

