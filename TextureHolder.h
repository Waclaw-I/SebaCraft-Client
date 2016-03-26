#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class TextureHolder
{
private:
	static Texture menuButtonTextures[12];
	static Texture resolutionButtonTextures[15];

public:

	static void initializeTextureArrays();
	static Texture & getMenuButtonTexture(int index);
	static Texture & getResolutionButtonTexture(int index);
};