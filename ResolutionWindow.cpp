#include "ResolutionWindow.h"
#include "TextureHolder.h"
#include "GraphMethods.h"
#include "GameLogic.h"
#include "Button.h"

#include <iostream>

using namespace sf;


ResolutionWindow::ResolutionWindow()
{
	resolutionX = 500;
	resolutionY = 300; // narazie na sztywno. Potrzeba menu do wyboru

	resolutionWindow = new RenderWindow(VideoMode(resolutionX, resolutionY, 32), "Change Resolution");

	Button b640x480(100, 60, TextureHolder::getResolutionButtonTexture(0), TextureHolder::getResolutionButtonTexture(1), TextureHolder::getResolutionButtonTexture(2));
	Button b800x600(100, 60, TextureHolder::getResolutionButtonTexture(3), TextureHolder::getResolutionButtonTexture(4), TextureHolder::getResolutionButtonTexture(5));
	Button b1024x768(100, 60, TextureHolder::getResolutionButtonTexture(6), TextureHolder::getResolutionButtonTexture(7), TextureHolder::getResolutionButtonTexture(8));
	Button bFullscreen(100, 60, TextureHolder::getResolutionButtonTexture(9), TextureHolder::getResolutionButtonTexture(10), TextureHolder::getResolutionButtonTexture(11));
	Button bOk(100, 60, TextureHolder::getResolutionButtonTexture(12), TextureHolder::getResolutionButtonTexture(13), TextureHolder::getResolutionButtonTexture(14));


	Button * bTable[4]; // we ll use it for logic of pressed buttons
	bool buttonSelected[4];

	for (int i = 0; i < 4; i++) buttonSelected[i] = false;

	bTable[0] = &b640x480;
	bTable[1] = &b800x600;
	bTable[2] = &b1024x768;
	bTable[3] = &bFullscreen;

	b640x480.setPosition((resolutionX / 2 - b640x480.getWidth() / 2 - 180), (resolutionY / 2 - b640x480.getHeight() / 2 - 100));
	b800x600.setPosition((resolutionX / 2 - b800x600.getWidth() / 2 - 180), (resolutionY / 2 - b800x600.getHeight() / 2 - 20));
	b1024x768.setPosition((resolutionX / 2 - b1024x768.getWidth() / 2 + 180), (resolutionY / 2 - b1024x768.getHeight() / 2 - 100));
	bFullscreen.setPosition((resolutionX / 2 - bFullscreen.getWidth() / 2 + 180), (resolutionY / 2 - bFullscreen.getHeight() / 2 - 20));
	bOk.setPosition((resolutionX / 2 - bFullscreen.getWidth() / 2 + 180), (resolutionY / 2 - bFullscreen.getHeight() / 2 + 100));




	backgroundTexture.loadFromFile("Graphs/Menu/Resolution/resolutionBackground.jpg");

	backgroundSprite.setTexture(backgroundTexture);
	GraphMethods::ScaleSprite(backgroundSprite, resolutionX, resolutionY);

	while (resolutionWindow->isOpen())
	{
		Event event;

		while (resolutionWindow->pollEvent(event))
		{
			if (event.type == Event::Closed) resolutionWindow->close();
		}

			
			
		for (int i = 0; i < 4; i++)
		{
			if (buttonSelected[i] == false) bTable[i]->changeVisibleSprite(*resolutionWindow);
			if (bTable[i]->isButtonPressed(*resolutionWindow))
			{
				buttonSelected[i] = true;
				for (int j = 0; j < i; j++) buttonSelected[j] = false;
				for (int j = i + 1; j < 4; j++) buttonSelected[j] = false;
			}
		}

		bOk.changeVisibleSprite(*resolutionWindow);

		if (bOk.isButtonPressed(*resolutionWindow))
		{
			if (buttonSelected[0])
			{
				GameLogic::setResolutionX(640); GameLogic::setResolutionY(480);
			}
			if (buttonSelected[1])
			{
				GameLogic::setResolutionX(800); GameLogic::setResolutionY(600);
			}
			if (buttonSelected[2])
			{
				GameLogic::setResolutionX(1024); GameLogic::setResolutionY(768);
			}
			if (buttonSelected[3])
			{
				GameLogic::setResolutionX(VideoMode::getDesktopMode().width); GameLogic::setResolutionY(VideoMode::getDesktopMode().height);
			}
			resolutionWindow->close();
		}

		resolutionWindow->clear(Color::Cyan);
		resolutionWindow->draw(backgroundSprite);
		resolutionWindow->draw(b640x480.getSprite());
		resolutionWindow->draw(b800x600.getSprite());
		resolutionWindow->draw(b1024x768.getSprite());
		resolutionWindow->draw(bFullscreen.getSprite());
		resolutionWindow->draw(bOk.getSprite());
	
		resolutionWindow->display();
	}
}