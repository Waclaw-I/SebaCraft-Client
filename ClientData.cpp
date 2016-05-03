#include "ClientData.h"
#include "GameLogic.h"
#include "Player.h"
#include "UsefulMethods.h"

#include <Windows.h>
#include <thread>


string ClientData::getReceivedChatMessage() { return receivedChatMessage; }
bool ClientData::getNewMessageConfirmation() { return newMessage; }
bool ClientData::getCanStay() { return canStay; }
SOCKET & ClientData::getSocket() { return Connection; }
void ClientData::setNewMessageConfirmation(bool x) { newMessage = x; }

string ClientData::getNickname() { return this->nickname; }
int ClientData::getID() { return this->ID; }
int ClientData::getShipType() { return this->shipType; }
void ClientData::setNickname(string nickname) { this->nickname = nickname; }
void ClientData::setShipType(int shipType) { this->shipType = shipType; }
void ClientData::setID(int ID) { this->ID = ID; }


ClientData::ClientData(string ip, int port)
{
	WSAData wsaData;
	WORD DllVersion = MAKEWORD(2, 1);
	if (WSAStartup(DllVersion, &wsaData) != 0)
	{
		MessageBoxA(NULL, "Winsock startup failed", "Error", MB_OK | MB_ICONERROR);
		exit(0);
	}

	addr.sin_addr.s_addr = inet_addr(ip.c_str());
	addr.sin_port = htons(port);
	addr.sin_family = AF_INET;
	clientPtr = this;

}

bool ClientData::processPacket(Packet packetType)
{
	switch (packetType)
	{
		case pMessage:
		{
			if (!getMessage(receivedChatMessage))
			{
				return false;
			}
			newMessage = true;
			break;
		}

		case pConsole: // error messages
		{
			if (!getConsoleMessage())
			{
				return false;
			}
			canStay = false;
			break;
		}

		case pNewPlayer: // new player has joined the game!
		{ // RETRIEVING NICKNAME, SHIP TYPE AND ID FROM THE SERVER AND CREATING NEW PLAYER OBJECT FOR OUR VECTOR OF PLAYERS
			string data;
			if (!getMessage(data)) return false;
			int position;
			position = data.find("\t");
			string nick = data.substr(1, data.size() - (data.size() - position + 1));
			int id = atoi(data.substr(position, data.size()).c_str());
			int shipType = atoi(data.substr(0, 1).c_str());
			GameLogic::getPlayersList().push_back(new Player(nick, *UsefulMethods::getSpaceShipType(shipType), id));
			for (int i = 0; i < GameLogic::getPlayersList().size(); i++)
			{
				cout << "Gracz: " << GameLogic::getPlayersList()[i]->getName() << " ID: " << GameLogic::getPlayersList()[i]->getID() << endl;
			}
			break;
		}

		case pInitialize:
		{
			string data;
			if (!getMessage(data)) return false; // receiving ID from server for OURSELVES
			ID = atoi(data.c_str());
			std::cout << "Otrzymano ID: " << ID;
			break;
		}

		case pRemovePlayer:
		{
			string data;
			if (!getMessage(data)) return false; // receiving ID of removed player from the server
			int id = atoi(data.c_str());

			for (int i = 0; i < GameLogic::getPlayersList().size(); i++)
			{
				if (GameLogic::getPlayersList()[i]->getID() == id)
				{
					delete GameLogic::getPlayersList()[i];
					GameLogic::getPlayersList().erase(GameLogic::getPlayersList().begin() + i);
					cout << "USUNIETO GRACZA O ID: " << id << endl;
				}
			}
			break;
		}

		case pPosition:
		{
			string position;
			
			if (!getMessage(position)) return false;			

			int xParserPos = position.find("X");
			int yParserPos = position.find("Y");
			int rParserPos = position.find("R");

			int ID = atoi(position.substr(0, xParserPos).c_str());
			double positionX = atof(position.substr(xParserPos + 1, yParserPos - xParserPos - 1).c_str());
			double positionY = atof(position.substr(yParserPos + 1, rParserPos - yParserPos - 1).c_str());
			double rotation = atof(position.substr(rParserPos + 1, position.size() - rParserPos - 1).c_str());

			for (int i = 0; i < GameLogic::getPlayersList().size(); i++)
			{
				if (GameLogic::getPlayersList()[i]->getID() == ID)
				{
					GameLogic::getPlayersList()[i]->getShip().setPositionX(positionX);
					GameLogic::getPlayersList()[i]->getShip().setPositionY(positionY);
					GameLogic::getPlayersList()[i]->getShip().setRotation(rotation);
				}
			}
			break;
		}

		default:
		{
			cout << "Unrecognized packet: " << packetType << endl;
			break;
		}
		
	}
	return true;
}

void ClientData::ClientThreadGetInfo() // NEW THREAD TO RECEIVE INFORMATIONS FROM THE SERVER
{
	Packet packetType;
	while (GameLogic::getGameOn())
	{
		if (!getPacketType(packetType)) std::cout << "Failed to get packet from server..." << std::endl;
		if (!processPacket(packetType)) std::cout << "Failed to process packet from server..." << std::endl;

	}
	cout << "Lost connection to the server - ClientThread" << endl;
	if (closeConnection()) cout << "Socket was closed successfuly" << endl;
	else cout << "Couldn't close the socket" << endl;
}

void ClientData::ClientThreadSendInfo(Player * player)
{
	while (GameLogic::getGameOn())
	{
		string position = to_string(player->getShip().getPositionX()) + "X" + to_string(player->getShip().getPositionY()) + "Y" + to_string(player->getShip().getRotation()) + "R";
		if (!sendPosition(position)) std::cout << "Failed to send position packet to the server" << std::endl;
		Sleep(16);
	}
}

bool ClientData::Connect()
{
	Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeofaddr) != 0)
	{
		cout << "Failed to Connect" << endl;
		return false;
	}

	cout << "Connected!" << endl;
	return true;
}

bool ClientData::closeConnection()
{
	if (closesocket(Connection) == SOCKET_ERROR)
	{
		if (WSAGetLastError() == WSAENOTSOCK) return true;
		cout << "Failed to close the socket" << endl;
		return false;
	}
	return true;
}



// ##############SENDING TO SERVER METHODS########################

bool ClientData::sendPacketType(Packet packetType)
{
	int check = send(Connection, (char*)&packetType, sizeof(Packet), NULL);
	if (check == SOCKET_ERROR)
	{
		cout << "Failed to send packet type" << endl;
		return false;
	}
	return true;
}

bool ClientData::sendMessageSize(int size)
{
	int check = send(Connection, (char*)&size, sizeof(int), NULL);
	if (check == SOCKET_ERROR)
	{
		cout << "Failed to send message size" << endl;
		return false;
	}
	return true; // size sent successfuly
}

bool ClientData::sendMessage(string & message)
{
	if (!sendPacketType(pMessage))
	{
		cout << "Failed to send packet type" << endl;
		return false;
	}
	int bufferLength = message.size();
	if (!sendMessageSize(bufferLength))
	{
		cout << "Failed to message size" << endl;
		return false;
	}

	int check = send(Connection, message.c_str(), bufferLength, NULL);
	if (check == SOCKET_ERROR)
	{
		cout << "Failed to send message" << endl;
		return false;
	}
	return true; // Message sent successfuly
}

bool ClientData::sendInitialization(string & message)
{
	if (!sendPacketType(pInitialize))
	{
		cout << "Failed to send Initialize packet" << endl;
		return false;
	}
	int bufferLength = message.size();
	if (!sendMessageSize(bufferLength))
	{
		cout << "Failed to message size" << endl;
		return false;
	}

	int check = send(Connection, message.c_str(), bufferLength, NULL);
	if (check == SOCKET_ERROR)
	{
		cout << "Failed to send message" << endl;
		return false;
	}
	return true; // Message sent successfuly
}

bool ClientData::sendLeftAlert(string & message)
{
	if (!sendPacketType(pRemovePlayer))
	{
		cout << "Failed to send Initialize packet" << endl;
		return false;
	}
	int bufferLength = message.size();
	if (!sendMessageSize(bufferLength))
	{
		cout << "Failed to message size" << endl;
		return false;
	}

	int check = send(Connection, message.c_str(), bufferLength, NULL);
	if (check == SOCKET_ERROR)
	{
		cout << "Failed to send message" << endl;
		return false;
	}
	return true; // Message sent successfuly
}

bool ClientData::sendPosition(string & message)
{
	if (!sendPacketType(pPosition))
	{
		cout << "Failed to send Position packet" << endl;
		return false;
	}
	int bufferLength = message.size();
	if (!sendMessageSize(bufferLength))
	{
		cout << "Failed to message size" << endl;
		return false;
	}

	int check = send(Connection, message.c_str(), bufferLength, NULL);
	if (check == SOCKET_ERROR)
	{
		cout << "Failed to send message" << endl;
		return false;
	}
	return true; // Message sent successfuly
}


// ##############RECEIVING FROM SERVER METHODS########################



bool ClientData::getPacketType(Packet & packetType)
{
	int check = recv(Connection, (char*)&packetType, sizeof(Packet), NULL);
	if (check == SOCKET_ERROR)
	{
		cout << "Couldn't get packet type properly" << endl;
		return false;
	}
	return true;
}

bool ClientData::getMessageSize(int & size)
{
	int check = recv(Connection, (char*)&size, sizeof(int), NULL);
	if (check == SOCKET_ERROR)
	{
		cout << "Couldn't get size of the message properly" << endl;
		return false;
	}
	return true; // size received successfuly
}

bool ClientData::getMessage(string & message)
{
	int bufferLength;
	if (!getMessageSize(bufferLength))
	{
		return false;
	}
	char * buffer = new char[bufferLength + 1];
	buffer[bufferLength] = '\0'; // last character to be null terminator
	
	int check = recv(Connection, buffer, bufferLength, NULL);
	message = buffer;
	delete[] buffer;
	
	if (check == SOCKET_ERROR)
	{
		cout << "Problem with getMessage occured" << endl;
		return false;
	}
	return true;
}

bool ClientData::getConsoleMessage()
{
	int bufferLength;
	if (!getMessageSize(bufferLength))
	{
		cout << "tutaj" << endl;
		return false;
	}
	char * buffer = new char[bufferLength + 1];
	buffer[bufferLength] = '\0'; // last character to be null terminator

	int check = recv(Connection, buffer, bufferLength, NULL);
	cout << buffer;
	delete[] buffer;

	if (check == SOCKET_ERROR)
	{
		cout << "Problem with getConsoleMessage occured" << endl;
		return false;
	}
	return true;
}

