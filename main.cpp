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
		string ip;
		cout << "Podaj IP: ";
		cin >> ip;
		ClientData client(ip, 33355);

		if (!client.Connect())
		{
			cout << "Failed to connect to server" << endl;
			_getch();
			return 0;
		}

		else
		{
			string nick;
			string shipType;
			cout << "Podaj swoj pseudonim, gwiezdny pilocie: ";
			cin >> nick;
			cout << "Wybierz swoj statek: \n\n1. Zwiadowca\n2. Smieciara" << endl;
			cin >> shipType;
			client.setNickname(nick); // this all ll be placed in a nice GUI! At least I hope so
			client.setShipType(atoi(shipType.c_str()));

			string Initializer = shipType + nick;
			client.sendInitialization(Initializer);
			Game game(client);
		}

		if (!GameLogic::getGameOn)
		{
			string msg = "";
			client.sendLeftAlert(msg);
		}


	}


	std::cout << "\n\n";
	std::cout << "You have been disconnected from the server" << std::endl;
	system("pause");

}

