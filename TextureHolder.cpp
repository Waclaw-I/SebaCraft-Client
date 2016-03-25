#include "TextureHolder.h"

using namespace sf;

Texture TextureHolder::menuButtonTextures[];

Texture & TextureHolder::getMenuButtonTexture(int index)
{
	return menuButtonTextures[index];
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

}