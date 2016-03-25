#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class TextureHolder
{
private:
	static Texture menuButtonTextures[12];

public:

	static void initializeTextureArrays();
	static Texture & getMenuButtonTexture(int index);
};