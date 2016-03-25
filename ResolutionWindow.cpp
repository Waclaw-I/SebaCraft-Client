#include "ResolutionWindow.h"
#include "GraphMethods.h"

using namespace sf;


ResolutionWindow::ResolutionWindow()
{
	resolutionX = 500;
	resolutionY = 300; // narazie na sztywno. Potrzeba menu do wyboru

	resolutionWindow = new RenderWindow(VideoMode(resolutionX, resolutionY, 32), "Change Resolution");

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

		resolutionWindow->clear(Color::Cyan);
		resolutionWindow->draw(backgroundSprite);
	
		resolutionWindow->display();
	}
}