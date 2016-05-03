#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#pragma comment(lib,"ws2_32.lib") //Required for WinSock
#include <WinSock2.h> //For win sockets
#include <string>
#include <iostream>

#include "Player.h"
using namespace std;

enum Packet
{
	pMessage,
	pConsole,
	pInitialize,
	pNewPlayer,
	pRemovePlayer,
	pPosition
};

class ClientData
{
private:


	string receivedChatMessage; // container for messages from other players
	bool newMessage = false; // if true, we ll put newest message into the chat window
	bool canStay = true; // if false, player ll be kicked from server and game window will close 

	int ID;
	string nickname; // these variables are used to create Player object
	int shipType; // later, when the game starts

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

	void ClientThreadGetInfo();
	void ClientThreadSendInfo(Player * player);

	bool sendMessage(string & message);
	bool sendInitialization(string & message); // information about nickname, choosen ship etc
	bool sendLeftAlert(string & message);
	bool sendPosition(string & message);
	bool closeConnection();

	string getReceivedChatMessage();
	bool getNewMessageConfirmation();
	bool getCanStay();
	void setNewMessageConfirmation(bool x);

	string getNickname();
	int getID();
	int getShipType();
	void setNickname(string nickname);
	void setShipType(int shipType);
	void setID(int);

	SOCKET & getSocket();
};

static ClientData * clientPtr;