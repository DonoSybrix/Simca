/*
 * PopupConfig.cpp
 *
 *  Created on: 20 mai 2011
 *      Author: Axel GUILMIN
 */

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "PopupConfig.hpp"

////////////////////////////////////////////////////////////
/// Default constructor
////////////////////////////////////////////////////////////
PopupConfig::PopupConfig()
{
	this->width = 200;
	this->height = 360;
	network = NetworkEngine::getInstance();

	popup = new sf::RenderWindow(sf::VideoMode(width,height,32), "SIMCA - Config");
	popup->SetPosition(10,10);
}

////////////////////////////////////////////////////////////
/// virtual destructor
////////////////////////////////////////////////////////////
PopupConfig::~PopupConfig()
{

}

////////////////////////////////////////////////////////////
/// Display the popup, return the mode to apply at behavoir engine
////////////////////////////////////////////////////////////
int PopupConfig::Display()
{
	// Gestion des evenements
	const sf::Input& input = popup->GetInput();

	while(popup->IsOpened())
	{
		// The standard Event loop
		sf::Event Event;
		while(popup->GetEvent(Event))
		{
			if(Event.Type == sf::Event::Closed)
				popup->Close();
			if((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape))
				popup->Close();

			// This is the function that takes care of which control
			// has focus out of all the controls registered to your
			// GuiContainer.
			cpGui.ProcessKeys(&Event);
		}

		// raz
		popup->Clear();

		// Background
		tondreLeGazon();

		popup->Display();
	}

	return 0;
}


