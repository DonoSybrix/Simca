/*
 * PopupLoad.hpp
 *
 *  Created on: 20 mai 2011
 *      Author: Axel GUILMIN
 */

#ifndef POPUPLOAD_HPP_
#define POPUPLOAD_HPP_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "../utils/defines.hpp"
#include "../utils/library.hpp"

#include "../network/NetworkEngine.hpp"

#include <SFML/Graphics.hpp>
#include "./cpGUI/cpGUI.h"

#include "Popup.hpp"

class PopupLoad : public Popup
{
public :
	PopupLoad();
	~PopupLoad();
	int Display();
	int getSelectedCrossroad();
	int getSelectedSimulation();
private :
	int selectedCrossroad;
	int selectedSimulation;
	int mode;

	// Label for crossroadss selection
	sf::String* labelCrossroad;
	// Selection box to choose a Crossroad
	cp::cpSelectionBox* selBoxCrossroad;
	std::vector<sf::String> selBoxCrossroadValues ;
	// Buttons for Crossroad selection
	cp::cpButton* btnCrossroadNew;
	cp::cpButton* btnCrossroadOpen;
	cp::cpButton* btnCrossroadDelete;
	cp::cpButton* btnCrossroadRename;
	// Label for simulation selection
	sf::String* labelSimulation;
	// Selection box to choose a Simulation
	cp::cpSelectionBox* selBoxSimulation;
	// Buttuns for Simulation selection
	cp::cpButton* btnSimulationNew;
	cp::cpButton* btnSimulationOpen;
	cp::cpButton* btnSimulationDelete;
	cp::cpButton* btnSimulationRename;
	// Textbox used to ask a name (renaming or creating item)
	cp::cpTextInputBox* inputBox;

	NetworkEngine* network;

	// intern functions
	void SimulationOpen();
	void CrossroadOpen();
	void CrossroadNew();
	void SimulationNew();
	void CrossroadDelete();
	void SimulationDelete();
};

#endif /* POPUPLOAD_HPP_ */
