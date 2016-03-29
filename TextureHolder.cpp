#include "TextureHolder.h"

using namespace sf;

Texture TextureHolder::menuButtonTextures[];
Texture TextureHolder::resolutionButtonTextures[];
Texture TextureHolder::shipsTextures[];
Texture TextureHolder::GUItextures[];

Texture & TextureHolder::getMenuButtonTexture(int index)
{
	return menuButtonTextures[index];
}

Texture & TextureHolder::getResolutionButtonTexture(int index)
{
	return resolutionButtonTextures[index];
}

Texture & TextureHolder::getShipsTextures(int index)
{
	return shipsTextures[index];
}

Texture & TextureHolder::getGUItextures(int index)
{
	return GUItextures[index];
}

void TextureHolder::initializeTextureArrays()
{
	menuButtonTextures[0].loadFromFile("Graphs/Menu/bIdleLogin.png");
	menuButtonTextures[1].loadFromFile("Graphs/Menu/bHoveredLogin.png");
	menuButtonTextures[2].loadFromFile("Graphs/Menu/bPressedLogin.png");
	menuButtonTextures[3].loadFromFile("Graphs/Menu/bIdleRegister.png");
	menuButtonTextures[4].loadFromFile("Graphs/Menu/bHoveredRegister.png");
	menuButtonTextures[5].loadFromFile("Graphs/Menu/bPressedRegister.png");
	menuButtonTextures[6].loadFromFile("Graphs/Menu/bIdleResolution.png");
	menuButtonTextures[7].loadFromFile("Graphs/Menu/bHoveredResolution.png");
	menuButtonTextures[8].loadFromFile("Graphs/Menu/bPressedResolution.png");
	menuButtonTextures[9].loadFromFile("Graphs/Menu/bIdleExit.png");
	menuButtonTextures[10].loadFromFile("Graphs/Menu/bHoveredExit.png");
	menuButtonTextures[11].loadFromFile("Graphs/Menu/bPressedExit.png");

	resolutionButtonTextures[0].loadFromFile("Graphs/Menu/Resolution/bIdle640x480.png");
	resolutionButtonTextures[1].loadFromFile("Graphs/Menu/Resolution/bHovered640x480.png");
	resolutionButtonTextures[2].loadFromFile("Graphs/Menu/Resolution/bSelected640x480.png");
	resolutionButtonTextures[3].loadFromFile("Graphs/Menu/Resolution/bIdle800x600.png");
	resolutionButtonTextures[4].loadFromFile("Graphs/Menu/Resolution/bHovered800x600.png");
	resolutionButtonTextures[5].loadFromFile("Graphs/Menu/Resolution/bSelected800x600.png");
	resolutionButtonTextures[6].loadFromFile("Graphs/Menu/Resolution/bIdle1024x768.png");
	resolutionButtonTextures[7].loadFromFile("Graphs/Menu/Resolution/bHovered1024x768.png");
	resolutionButtonTextures[8].loadFromFile("Graphs/Menu/Resolution/bSelected1024x768.png");
	resolutionButtonTextures[9].loadFromFile("Graphs/Menu/Resolution/bIdleFullscreen.png");
	resolutionButtonTextures[10].loadFromFile("Graphs/Menu/Resolution/bHoveredFullscreen.png");
	resolutionButtonTextures[11].loadFromFile("Graphs/Menu/Resolution/bSelectedFullscreen.png");
	resolutionButtonTextures[12].loadFromFile("Graphs/Menu/Resolution/bIdleOk.png");
	resolutionButtonTextures[13].loadFromFile("Graphs/Menu/Resolution/bHoveredOk.png");
	resolutionButtonTextures[14].loadFromFile("Graphs/Menu/Resolution/bPressedOk.png");

	shipsTextures[0].loadFromFile("Graphs/Game/smallFighter.png");

	GUItextures[0].loadFromFile("Graphs/Game/GUIpanel.png");

}