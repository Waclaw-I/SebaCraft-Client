#include "ClientData.h"

#include <thread>


string ClientData::getReceivedChatMessage() { return receivedChatMessage; }
bool ClientData::getNewMessageConfirmation() { return newMessage; }
bool ClientData::getCanStay() { return canStay; }
SOCKET & ClientData::getSocket() { return Connection; }
void ClientData::setNewMessageConfirmation(bool x) { newMessage = x; }

string ClientData::getNickname() { return this->nickname; }
void ClientData::setNickname(string nickname) { this->nickname = nickname; }


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

		default:
		{
			cout << "Unrecognized packet: " << packetType << endl;
			break;
		}
		
	}
	return true;
}

void ClientData::ClientThread() // NEW THREAD TO RECEIVE INFORMATIONS FROM THE SERVER
{
	Packet packetType;
	while (true)
	{
		if (!getPacketType(packetType)) break;
		if (!processPacket(packetType)) break;

	}
	cout << "Lost connection to the server - ClientThread" << endl;
	if (closeConnection()) cout << "Socket was closed successfuly" << endl;
	else cout << "Couldn't close the socket" << endl;
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
	//CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientThread, NULL, NULL, NULL); IT WONT BE NEEDED, PROBABLY
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
		cout << "tutaj" << endl;
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

