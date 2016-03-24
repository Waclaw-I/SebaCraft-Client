#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class TextureHolder
{
private:
	static Texture menuButtonTextures[6];

public:

	static void initializeTextureArrays();
	static Texture & getMenuButtonTexture(int index);
};