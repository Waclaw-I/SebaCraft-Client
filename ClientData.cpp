#include "ClientData.h"


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
			string message;
			if (!getMessage(message)) return false;
			cout << message << endl;
			break;
		}

		default:
		{
			cout << "Unrecognized packet: " << packetType << endl;
			break;
		}
		return true;
	}
}

void ClientData::ClientThread()
{
	Packet packetType;
	while (true)
	{
		if (!clientPtr->getPacketType(packetType)) break;
		if (!clientPtr->processPacket(packetType)) break;
	}
	cout << "Lost connection to the server" << endl;
	if (clientPtr->closeConnection()) cout << "Socket was closed successfuly" << endl;
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
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientThread, NULL, NULL, NULL);
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

bool ClientData::getPacketType(Packet & packetType)
{
	int check = recv(Connection, (char*)&packetType, sizeof(Packet), NULL);
	if (check == SOCKET_ERROR)
	{
		return false;
		cout << "Couldn't get packet type properly" << endl;
	}
	return true;
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

bool ClientData::getMessage(string & message)
{
	int bufferLength;
	if (!getMessageSize(bufferLength))
	{
		cout << "dd" << endl;
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