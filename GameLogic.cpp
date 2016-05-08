#include "GameLogic.h"

vector<Player *> GameLogic::playersList;
ClientData GameLogic::myClient;

int GameLogic::resolutionX = 800;
int GameLogic::resolutionY = 600;
bool GameLogic::gameStarted = false;
bool GameLogic::GameOn = false;

int GameLogic::getResolutionX() { return resolutionX; }
int GameLogic::getResolutionY() { return resolutionY; }
bool GameLogic::getGameStarted() { return gameStarted; }
bool GameLogic::getGameOn() { return GameOn; }
vector<Player *> & GameLogic::getPlayersList() { return playersList; }
ClientData & GameLogic::getClientData() { return myClient; }

void GameLogic::setResolutionX(int x) { resolutionX = x; }
void GameLogic::setResolutionY(int y) { resolutionY = y; }
void GameLogic::setGameStarted(bool x) { gameStarted = x; }
void GameLogic::setGameOn(bool x) { GameOn = x; }

void GameLogic::sendMGunBulletToServer(Bullet * bullet) // 1 for MGun type of bullet
{
	string x, y, r, speed, duration, damage;

	x = to_string(bullet->getPositionX());
	y = to_string(bullet->getPositionY());
	r = to_string(bullet->getRotation());

	speed = to_string(bullet->getSpeed());
	duration = to_string(bullet->getDuration());
	damage = to_string(bullet->getDamage());

	string message = "1T" + x + "X" + y + "Y" + r + "R" + speed + "S" + duration + "D" + damage + "A";
	myClient.sendBullet(message); // message goes to the server
}
