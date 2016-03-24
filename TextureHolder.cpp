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

}