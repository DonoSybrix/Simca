////////////////////////////////////////////////////////////
//
// Simca
// Copyright (C) 2011 Orhan Donovan ( sybrix44@gmail.com )
//
// - Author : Orhan Donovan.
// - Create : 14/04/2011.
// - Desc.  : Simulation to load, to save, ...
//
////////////////////////////////////////////////////////////

#ifndef SIMULATION_HPP
#define SIMULATION_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "../utils/library.hpp"
#include "../utils/other.hpp"
#include "../entities/entitiesList.hpp"

class Data
{
    public:

        // Constructor / Destructor.
		Data();
        ~Data();

        // Clear the map
        void Clear();

        // Load a map.
        void Load( std::string levelName );

        // Save a map.
        void Save();

        // Recuperation des entites
        std::vector<Entity*>* GetEntities();

        // Recuperation des routes
        std::vector<Road*>* GetRoads();

    private:

        // All entities of the map
        std::vector<Entity*> myEntities;

        // Liste des routes
        std::vector<Road*> myRoads;

        // Simulation name
        std::string myDataName;
};

#endif // SIMULATION_HPP
