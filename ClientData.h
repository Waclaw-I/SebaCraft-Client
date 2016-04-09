#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#pragma comment(lib,"ws2_32.lib") //Required for WinSock
#include <WinSock2.h> //For win sockets
#include <string>
#include <iostream>
using namespace std;

enum Packet
{
	pMessage,
	pConsole
};

class ClientData
{
private:


	string receivedChatMessage; // container for messages from other players
	bool newMessage = false; // if true, we ll put newest message into the chat window
	bool canStay = true; // if false, player ll be kicked from server and game window will close 

	bool processPacket(Packet packetType);

	bool sendMessageSize(int size);
	bool sendPacketType(Packet packetType);

	bool getMessageSize(int & size);
	bool getPacketType(Packet & packetType);
	bool getMessage(string &message);
	bool getConsoleMessage();


	SOCKET Connection;//This client's connection to the server
	SOCKADDR_IN addr; //Address to be binded to our Connection socket
	int sizeofaddr = sizeof(addr); //Need sizeofaddr for the connect function
	
public:

	ClientData(string ip, int port);
	bool Connect();

	void ClientThread();

	bool sendMessage(string & message);
	bool closeConnection();

	string getReceivedChatMessage();
	bool getNewMessageConfirmation();
	bool getCanStay();
	void setNewMessageConfirmation(bool x);
};

static ClientData * clientPtr;