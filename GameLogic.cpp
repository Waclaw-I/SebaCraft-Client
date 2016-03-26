#include "GameLogic.h"

int GameLogic::resolutionX = 800;
int GameLogic::resolutionY = 600;
bool GameLogic::gameStarted = false;

int GameLogic::getResolutionX() { return resolutionX; }
int GameLogic::getResolutionY() { return resolutionY; }
bool GameLogic::getGameStarted() { return gameStarted; }

void GameLogic::setResolutionX(int x) { resolutionX = x; }
void GameLogic::setResolutionY(int y) { resolutionY = y; }
void GameLogic::setGameStarted(bool x) { gameStarted = x; }
