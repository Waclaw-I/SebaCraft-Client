#include <SFML/Graphics.hpp>
#include <conio.h>

#include "MainMenu.h"
#include "TextureHolder.h"
#include "GameLogic.h"
#include "Game.h"
#include "ClientData.h"


int main()
{
	TextureHolder::initializeTextureArrays();
	MainMenu Menu;
	if (GameLogic::getGameStarted())
	{
		ClientData client("25.0.252.153", 33355);

		if (!client.Connect())
		{
			cout << "Failed to connect to server" << endl;
			_getch();
			return 0;
		}

		else Game game(client);

	}

}

