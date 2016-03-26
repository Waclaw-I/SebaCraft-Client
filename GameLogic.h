#pragma once

static class GameLogic
{
private:
	static int resolutionX;
	static int resolutionY;
public:

	static int getResolutionX();
	static int getResolutionY();

	static void setResolutionX(int x);
	static void setResolutionY(int y);
};