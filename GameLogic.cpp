#include "GameLogic.h"

vector<Player *> GameLogic::playersList;

int GameLogic::resolutionX = 800;
int GameLogic::resolutionY = 600;
bool GameLogic::gameStarted = false;
bool GameLogic::GameOn = false;

int GameLogic::getResolutionX() { return resolutionX; }
int GameLogic::getResolutionY() { return resolutionY; }
bool GameLogic::getGameStarted() { return gameStarted; }
bool GameLogic::getGameOn() { return GameOn; }
vector<Player *> & GameLogic::getPlayersList() { return playersList; }

void GameLogic::setResolutionX(int x) { resolutionX = x; }
void GameLogic::setResolutionY(int y) { resolutionY = y; }
void GameLogic::setGameStarted(bool x) { gameStarted = x; }
void GameLogic::setGameOn(bool x) { GameOn = x; }
