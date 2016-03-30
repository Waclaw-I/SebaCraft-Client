#pragma once

static class GameLogic
{
private:
	static int resolutionX;
	static int resolutionY;

	static bool gameStarted;
	static bool GameOn;
public:

	static int getResolutionX();
	static int getResolutionY();
	static bool getGameStarted();
	static bool getGameOn();

	static void setResolutionX(int x);
	static void setResolutionY(int y);
	static void setGameStarted(bool x);
	static void setGameOn(bool x);
};