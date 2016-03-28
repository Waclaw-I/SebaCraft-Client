#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#pragma comment(lib,"ws2_32.lib") //Required for WinSock
#include <WinSock2.h> //For win sockets
#include <string>
#include <iostream>

using namespace std;

enum Packet
{
	pMessage
};

class ClientData
{
private:

	bool processPacket(Packet packetType);

	bool sendMessageSize(int size);
	bool sendPacketType(Packet packetType);

	bool getMessageSize(int & size);
	bool getPacketType(Packet & packetType);
	bool getMessage(string &message);

	static void ClientThread();

	SOCKET Connection;//This client's connection to the server
	SOCKADDR_IN addr; //Address to be binded to our Connection socket
	int sizeofaddr = sizeof(addr); //Need sizeofaddr for the connect function
	
public:

	ClientData(string ip, int port);
	bool Connect();

	bool sendMessage(string & message);
	bool closeConnection();
};

static ClientData * clientPtr;