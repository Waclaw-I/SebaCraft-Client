#pragma once
#include "vector";
#include "Player.h";
#include "ClientData.h"
#include "Bullet.h"

class GameLogic
{
private:
	static int resolutionX;
	static int resolutionY;

	static bool gameStarted;
	static bool GameOn;

	static ClientData myClient;

	static std::vector<Player *> playersList;
public:

	static int getResolutionX();
	static int getResolutionY();
	static bool getGameStarted();
	static bool getGameOn();
	static vector<Player *> & getPlayersList();

	static void setResolutionX(int x);
	static void setResolutionY(int y);
	static void setGameStarted(bool x);
	static void setGameOn(bool x);
	static ClientData & getClientData();
	static void sendMGunBulletToServer(Bullet * bullet);
	
};