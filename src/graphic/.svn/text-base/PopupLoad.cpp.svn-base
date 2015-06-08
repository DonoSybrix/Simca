/*
 * PopupLoad.cpp
 *
 *  Created on: 20 mai 2011
 *      Author: Axel GUILMIN
 */

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "PopupLoad.hpp"

////////////////////////////////////////////////////////////
/// Default constructor
////////////////////////////////////////////////////////////
PopupLoad::PopupLoad()
{
	this->width = 430;
	this->height = 360;
	this->mode = -1;
	this->selectedCrossroad = 0;
	this->selectedSimulation = 0;
	network = NetworkEngine::getInstance();
	selectedCrossroad = 0;

	popup = new sf::RenderWindow(sf::VideoMode(width,height,32), "SIMCA - Charger");
	popup->SetPosition(10,10);

	// Label for crossroadss selection
	labelCrossroad = new sf::String("Carrefour :", sf::Font::GetDefaultFont(), 14);
	labelCrossroad->SetPosition(10, 10);
	labelCrossroad->SetColor(sf::Color::Black);

	// Selection box to choose a Crossroad
	selBoxCrossroad = new cp::cpSelectionBox(popup, &cpGui, 10, 30, 200, 150);
	// No choice = ""
	selBoxCrossroad->AddChoice("");
	std::vector<Crossroad*>::iterator it;
	std::vector<Crossroad*> crossroads = network->GetAllCrossroad() ;
	for(it=crossroads.begin(); it!=crossroads.end(); it++)
		selBoxCrossroad->AddChoice((*it)->GetNom());
	selBoxCrossroad->SetFontSize(12);

	// Buttons for Crossroad selection
	btnCrossroadNew = new cp::cpButton(popup, &cpGui, "Nouveau", 10, 200, 200, 30);
	btnCrossroadNew->SetFontSize(12);
	btnCrossroadOpen = new cp::cpButton(popup, &cpGui, "Ouvrir", 10, 240, 200, 30);
	btnCrossroadOpen->SetFontSize(12);
	btnCrossroadDelete = new cp::cpButton(popup, &cpGui, "Supprimer", 10, 280, 200, 30);
	btnCrossroadDelete->SetFontSize(12);
	btnCrossroadRename = new cp::cpButton(popup, &cpGui, "Renomer", 10, 320, 200, 30);
	btnCrossroadRename->SetFontSize(12);

	// Label for simulation selection
	labelSimulation = new sf::String("Simulation :", sf::Font::GetDefaultFont(), 14);
	labelSimulation->SetPosition(210, 10);
	labelSimulation->SetColor(sf::Color::Black);

	// Selection box to choose a Crossroad
	selBoxSimulation = new cp::cpSelectionBox(popup, &cpGui, 220, 30, 200, 150);

	//for(int t=0; t < 14; t++)
	//	selBoxSimulation->AddChoice(choices[t]);
	selBoxSimulation->SetFontSize(12);

	// Buttuns for Simulation selection
	btnSimulationNew = new cp::cpButton(popup, &cpGui, "Nouveau", 220, 200, 200, 30);
	btnSimulationNew->SetFontSize(12);
	btnSimulationOpen = new cp::cpButton(popup, &cpGui, "Ouvrir", 220, 240, 200, 30);
	btnSimulationOpen->SetFontSize(12);
	btnSimulationDelete = new cp::cpButton(popup, &cpGui, "Supprimer", 220, 280, 200, 30);
	btnSimulationDelete->SetFontSize(12);
	btnSimulationRename = new cp::cpButton(popup, &cpGui, "Renomer", 220, 320, 200, 30);
	btnSimulationRename->SetFontSize(12);

	// Textbox used to ask a name (renaming or creating item)
	inputBox = new cp::cpTextInputBox(popup, &cpGui, "", 0, 0, 200, 15);

}

////////////////////////////////////////////////////////////
/// virtual destructor
////////////////////////////////////////////////////////////
PopupLoad::~PopupLoad()
{

}

////////////////////////////////////////////////////////////
/// Display the popup, return the mode to apply at behavoir engine
////////////////////////////////////////////////////////////
int PopupLoad::Display()
{
	// Gestion des evenements
	const sf::Input& input = popup->GetInput();

	// par defaut inputBix est masqué
	inputBox->Show(false);
	// Masquer la partie droite
	selBoxSimulation->Show(false);
	btnSimulationNew->Show(false);
	btnSimulationOpen->Show(false);
	btnSimulationDelete->Show(false);
	btnSimulationRename->Show(false);

	while(popup->IsOpened())
	{
		// The standard Event loop
		sf::Event Event;
		while(popup->GetEvent(Event))
		{
			inputBox->ProcessTextInput(&Event);

			if(Event.Type == sf::Event::Closed)
				popup->Close();
			if((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape))
				popup->Close();

			// This is the function that takes care of which control
			// has focus out of all the controls registered to your
			// GuiContainer.
			cpGui.ProcessKeys(&Event);
		}

		// After the events are processed, we need to check the state of every
		// control we create using your Input as a parameter.
		// Most controls will return an integer that will tell you the
		// mouse activity within that control.  For these controls, the
		// possible return values are included in an enumeration:
		// CP_STATE_MOUSE_ENTER, CP_STATE_MOUSE_EXIT, CP_STATE_MOUSE_IN,
		// CP_STATE_MOUSE_LBUTTON_DOWN, CP_STATE_MOUSE_LBUTTON_RELEASED,
		// CP_STATE_CHANGED, & CP_STATE_NONE
		// you can use these values to decide what to do.

		// maj selectedCrossroad
		CrossroadOpen();

		if(btnCrossroadNew->CheckState(&input) == cp::CP_ST_MOUSE_LBUTTON_RELEASED)
		{
			CrossroadNew();
		}

		if(btnCrossroadOpen->CheckState(&input) == cp::CP_ST_MOUSE_LBUTTON_RELEASED)
		{
			this->selectedSimulation = 0;
			popup->Close();
		}
		if(btnCrossroadDelete->CheckState(&input) == cp::CP_ST_MOUSE_LBUTTON_RELEASED)
		{
			CrossroadDelete();
		}
		//if(btnCrossroadRename->CheckState(&input) == cp::CP_ST_MOUSE_LBUTTON_RELEASED)
		//{
		//	popup->Close();
		//}
		if(btnSimulationNew->CheckState(&input) == cp::CP_ST_MOUSE_LBUTTON_RELEASED)
		{
			CrossroadOpen();
			SimulationNew();
		}
		if(btnSimulationOpen->CheckState(&input) == cp::CP_ST_MOUSE_LBUTTON_RELEASED)
		{
			SimulationOpen();
			popup->Close();
		}

		if(btnSimulationDelete->CheckState(&input) == cp::CP_ST_MOUSE_LBUTTON_RELEASED)
		{
			SimulationOpen();
			SimulationDelete();
		}
		//if(btnSimulationRename->CheckState(&input) == cp::CP_ST_MOUSE_LBUTTON_RELEASED)
		//{
		//	popup->Close();
		//}
		// inputBox validated
		if(inputBox->CheckState(&input) == cp::CP_ST_MOUSE_LBUTTON_RELEASED)
		{
			// Creation d'un nouveau Carrefour
			if( ! btnCrossroadNew->GetShow() )
				CrossroadNew();
			else if( ! btnSimulationNew->GetShow() )
				SimulationNew();
		}
		// Simulation selection
		if(selBoxSimulation->CheckState(&input) == cp::CP_ST_MOUSE_LBUTTON_RELEASED)
		{

		}
		// Crossroad selection
		if(selBoxCrossroad->CheckState(&input) == cp::CP_ST_MOUSE_LBUTTON_RELEASED)
		{
			int selection = selBoxCrossroad->GetSelection();
			if(selection != 0)
			{
				// Afficher la partie droite
				selBoxSimulation->Show(true);
				btnSimulationNew->Show(true);
				btnSimulationOpen->Show(true);
				btnSimulationDelete->Show(true);
				btnSimulationRename->Show(true);

				// Vider
				selBoxSimulation->choices.clear();
				// Afficher les simulation existantes
				std::string crossroadName = selBoxCrossroad->choices[selection].GetText();

				//std::string a = crossroadName.GetText() ;
				Crossroad* crossroad = network->GetCrossroad(crossroadName);
				std::set<int>::iterator idSimulation;
				for(idSimulation=crossroad->simulations.begin(); idSimulation!=crossroad->simulations.end(); idSimulation++)
					selBoxSimulation->AddChoice(network->GetSimulation(*idSimulation)->GetNom());
			}
			else
			{
				// Afficher la partie droite
				selBoxSimulation->Show(false);
				btnSimulationNew->Show(false);
				btnSimulationOpen->Show(false);
				btnSimulationDelete->Show(false);
				btnSimulationRename->Show(false);
			}
		}

		// raz
		popup->Clear();

		// Background
		tondreLeGazon();

		// Every object you create should have the Draw() function
		// called on every cycle.  If you don't want an object to
		// be visible, set Show(false) for that object.
		popup->Draw(*labelCrossroad);
		selBoxCrossroad->Draw();
		btnCrossroadNew->Draw();
		btnCrossroadOpen->Draw();
		btnCrossroadDelete->Draw();
		//btnCrossroadRename->Draw();

		popup->Draw(*labelSimulation);
		selBoxSimulation->Draw();
		btnSimulationNew->Draw();
		btnSimulationOpen->Draw();
		btnSimulationDelete->Draw();
		//btnSimulationRename->Draw();

		inputBox->Draw();

		popup->Display();
	}

	return mode;
}

////////////////////////////////////////////////////////////
///
/// Set the crossroad that will be opened by behavoir
///
////////////////////////////////////////////////////////////
void PopupLoad::CrossroadOpen()
{
	int selection = selBoxCrossroad->GetSelection();
	if( selection != 0)
	{
		mode = 1;
		std::string crossroadName = selBoxCrossroad->choices[selection].GetText();
		Crossroad* c = network->GetCrossroad( crossroadName );
		selectedCrossroad = c->GetIdCarrefour();
	}
}

////////////////////////////////////////////////////////////
///
/// Set the simulation that will be opened by behavoir
///
////////////////////////////////////////////////////////////
void PopupLoad::SimulationOpen()
{
	int selection = selBoxCrossroad->GetSelection();
	if( selection != 0 )
	{
		mode = 2;
		std::string crossroadName = selBoxCrossroad->choices[selection].GetText();
		Crossroad* c = network->GetCrossroad( crossroadName );
		selectedCrossroad = c->GetIdCarrefour();

		if( selBoxSimulation->GetSelection() != 0 )
		{
			std::string simulationName = selBoxSimulation->choices[selBoxSimulation->GetSelection()].GetText();
			Simulation* s = network->GetSimulation( c, simulationName );
			selectedSimulation = s->GetIdSimulation();
		}
	}
}

////////////////////////////////////////////////////////////
///
/// Create a new crossroad in the DB
///
////////////////////////////////////////////////////////////
void PopupLoad::CrossroadNew()
{

	if( btnCrossroadNew->GetShow() )
	{
		// Remplacer le bouton par un textbox
		btnCrossroadNew->Show(false);
		inputBox->SetPosition(btnCrossroadNew->GetPosition().x,btnCrossroadNew->GetPosition().y);
		inputBox->Show(true);
		inputBox->SetFocus(true);
	}
	else if(! inputBox->GetLabelText().compare(""))
	{
		// Reaffiche le bouton
		btnCrossroadNew->Show(true);
		inputBox->Show(false);
	}
	else
	{
		// Creation du nouveau RP en BDD
		std::cout << inputBox->GetLabelText() << std::endl ;
		Crossroad* cr = network->NewCrossroad(inputBox->GetLabelText()) ;
		cr->SetHeight(200);
		network->SaveCrossroad(cr);
		// Ajout dans la liste
		selBoxCrossroad->AddChoice(cr->GetNom());
		// Reaffiche le bouton
		btnCrossroadNew->Show(true);
		inputBox->Show(false);
	}
}

////////////////////////////////////////////////////////////
///
/// Create a new simulation in the DB
///
////////////////////////////////////////////////////////////
void PopupLoad::SimulationNew()
{

	if( btnSimulationNew->GetShow() )
	{
		// Remplacer le bouton par un textbox
		btnSimulationNew->Show(false);
		inputBox->SetPosition(btnSimulationNew->GetPosition().x,btnSimulationNew->GetPosition().y);
		inputBox->Show(true);
		inputBox->SetFocus(true);
	}
	else if(! inputBox->GetLabelText().compare(""))
	{
		// Reaffiche le bouton
		btnSimulationNew->Show(true);
		inputBox->Show(false);
	}
	else
	{
		// Creation du nouveau RP en BDD
		std::cout << inputBox->GetLabelText() << std::endl ;
		Simulation* s = network->NewSimulation(inputBox->GetLabelText(),network->GetCrossroad(selectedCrossroad)) ;
		network->SaveSimulation(s);
		// Ajout dans la liste
		selBoxSimulation->AddChoice(s->GetNom());
		// Reaffiche le bouton
		btnSimulationNew->Show(true);
		inputBox->Show(false);
	}
}

////////////////////////////////////////////////////////////
///
/// Delete a Crossroad from the DB
///
////////////////////////////////////////////////////////////
void PopupLoad::CrossroadDelete()
{
	int selection = selBoxCrossroad->GetSelection();
	if(selection != 0)
	{
		selBoxCrossroad->choices.clear();

		network->DelCrossroad(network->GetCrossroad(selectedCrossroad));

		selBoxCrossroad->AddChoice("");
		std::vector<Crossroad*>::iterator it;
		std::vector<Crossroad*> crossroads = network->GetAllCrossroad() ;
		for(it=crossroads.begin(); it!=crossroads.end(); it++)
			selBoxCrossroad->AddChoice((*it)->GetNom());
	}
}

////////////////////////////////////////////////////////////
///
/// Delete a Simulation from the DB
///
////////////////////////////////////////////////////////////
void PopupLoad::SimulationDelete()
{
	selBoxSimulation->choices.clear();

	network->DelSimulation(network->GetSimulation(selectedSimulation));

	int selection = selBoxCrossroad->GetSelection();
	std::string crossroadName = selBoxCrossroad->choices[selection].GetText();

	Crossroad* crossroad = network->GetCrossroad(crossroadName);
	std::set<int>::iterator idSimulation;
	for(idSimulation=crossroad->simulations.begin(); idSimulation!=crossroad->simulations.end(); idSimulation++)
		selBoxSimulation->AddChoice(network->GetSimulation(*idSimulation)->GetNom());
}

////////////////////////////////////////////////////////////
///
/// Acces selected items
///
////////////////////////////////////////////////////////////
int PopupLoad::getSelectedCrossroad()
{
	return this->selectedCrossroad;
}
int PopupLoad::getSelectedSimulation()
{
	return this->selectedSimulation;
}

