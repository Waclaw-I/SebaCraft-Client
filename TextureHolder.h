#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class TextureHolder
{
private:
	static Texture menuButtonTextures[12];
	static Texture resolutionButtonTextures[15];
	static Texture shipsTextures[2];
	static Texture GUItextures[3];
	static Texture backgroundTextures[2];

	static Font fonts[1];

public:

	static void initializeTextureArrays();
	static Texture & getMenuButtonTexture(int index);
	static Texture & getResolutionButtonTexture(int index);
	static Texture & getShipsTextures(int index);
	static Texture & getGUItextures(int index);
	static Texture & getBackgroundTextures(int index);

	static Font & getFonts(int index);
};