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
		//25.0.252.153
		ClientData client("127.0.0.1", 33355);

		if (!client.Connect())
		{
			cout << "Failed to connect to server" << endl;
			_getch();
			return 0;
		}

		else
		{
			string nick;
			cout << "Podaj swoj pseudonim, gwiezdny pilocie: ";
			cin >> nick;
			client.setNickname(nick); // temporary only (whats wrong with my nickname anyway!?)
			client.sendInitialization(client.getNickname());
			Game game(client);
		}


	}

	std::cout << "\n\n";
	std::cout << "You have been disconnected from the server" << std::endl;
	system("pause");

}

