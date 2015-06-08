////////////////////////////////////////////////////////////
//
// Simca
// Copyright (C) 2011 Orhan Donovan ( sybrix44@gmail.com )
//
// - Author : Orhan Donovan.
// - Create : 04/02/2011.
// - Desc.  : Main of Game Engine
//
////////////////////////////////////////////////////////////


#ifndef BEHAVIORENGINE_HPP
#define BEHAVIORENGINE_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "../engine/Engine.hpp"

#include "../graphic/GraphicEngine.hpp"
#include "../physic/PhysicEngine.hpp"
#include "../network/NetworkEngine.hpp"

#include "../entities/entitiesList.hpp"

#include "Data.hpp"
#include "../utils/Pdf.hpp"

class BehaviorEngine : public Engine, public Singleton<BehaviorEngine>
{
    // Singleton
    friend class Singleton<BehaviorEngine>;

    public:

        // Constructor / Destructor.
		BehaviorEngine();
        virtual ~BehaviorEngine();

        // Init
        void Init();

        // Main of the game engine.
        virtual void Frame();

        // Events of user
        void Events();

        // Joue la simulation
        void PlaySimulation();

        // Call it to stop the game
        void Stop();

        // Get myPlay's value
        bool IsRunning();

        // Get Element under the mouse
        Entity* GetElementUnderMouse( unsigned int mouseX, unsigned int mouseY );

        // Indique si il y a eu un clique sur un element de la toolbar
        int FindClickOnToolBar( unsigned int mouseX, unsigned int mouseY );

        // Gestion des feux de singalisation
        void ManageTrafficLight();

        // Gestion des voitures
        void ManageCars();

        // Gestion des voitures sur le rond points
        void ManageDirtyCars();

        // Retourne la vitesse de la simulation
        float GetMySimulationSpeed() const;

        // Call it to clear the map
        void Clear();

        // Change the execution mode
        void setMode( int m );

    private:

        // App state (false => exit app)
        bool myPlay;

        /* Mode
         * 0 - Launching
		 * 1 - Crossroad config ( impossible de lancer une simu / rapport )
		 * 2 - Simulation config ( impossible de modifier le rond-point )
		 * 3 - Playing
         */
        unsigned int mode;

        // Indique si l'utilisateur modifie actuellement le rond point
        bool isEditingCrossRoad;

        // Vitesse de la simulation
        float mySimulationSpeed;

        // The map.
        Data  myData;

        // Element moves by the user
        Entity* currentEditingEntity;

        // Pointeur vers le feu de signalisation en cours d'utilisation
        TrafficLights *myCurrentTrafficLight;

        // Utiliser pour gérer les feux de signalisation
        sf::Clock myTrafficLightClock;

       // Contient les voitures sur le rond point
       std::vector<Car*> myDirtyCars;
};

#endif // BEHAVIORENGINE_HPP
