/*
 * networkEngine.hpp
 *
 *  Created on: 13 avr. 2011
 *      Author: Axel GUILMIN
 */

#ifndef NETWORKENGINE_HPP_
#define NETWORKENGINE_HPP_

#include "../engine/Engine.hpp"

#include "../behavior/BehaviorEngine.hpp"
#include "../graphic/GraphicEngine.hpp"
#include "../physic/PhysicEngine.hpp"

#include "../utils/defines.hpp"
#include "../utils/other.hpp"
#include "../utils/Singleton.hpp"

#include "../entities/entitiesList.hpp"

#include <sqlite3.h>

class NetworkEngine : public Engine, public Singleton<NetworkEngine>
{
    // Singleton
    friend class Singleton<NetworkEngine>;

    public:
        // Constructor / Destructor.
        NetworkEngine();
        virtual ~NetworkEngine();

        // New
        Crossroad* NewCrossroad(std::string nom) throw(std::logic_error);
        Road* NewRoad(std::string nom, Crossroad* crossroad) throw(std::logic_error);
        Simulation* NewSimulation(std::string nom, Crossroad* crossroad) throw(std::logic_error);
        Result* NewResult(Road* road, Simulation* simulation) throw(std::logic_error);

        // Select
        std::vector<Crossroad*> GetAllCrossroad();
        Crossroad* GetCrossroad(std::string nom) throw(std::logic_error);
        Crossroad* GetCrossroad(unsigned int id) throw(std::logic_error);
        Road* GetRoad(Crossroad* crossroad, std::string nom) throw(std::logic_error);
        Road* GetRoad(unsigned int id) throw(std::logic_error);
        Simulation* GetSimulation(Crossroad* crossroad, std::string nom) throw(std::logic_error);
        Simulation* GetSimulation(unsigned int id) throw(std::logic_error);
        Result* GetResult(Road* road, Simulation* simulation) throw(std::logic_error);

        // Update and Create : if id is null, a record is created in database
        int SaveCrossroad(Crossroad* crossroad);
        int SaveRoad(Road* road);
		int SaveSimulation(Simulation* simulation);
		int SaveResult(Result* result);

		// Delete a record
        void DelCrossroad(Crossroad* crossroad);
        void DelRoad(Road* road);
		void DelSimulation(Simulation* simulation);
		void DelResult(Result* result);

		virtual void Frame();
		void Demo();

    private:
		sqlite3* dataBase;
		char* errorMsg ;
		int connexion;
		std::string requete;

		// Callbacks de sqlite3_exec
		static int GetCrossroadCallback(void *returnedCrossroad, int nbLigne, char **values, char **colNames) ;
		static int GetRoadCallback(void* pReturnedRoad, int nbLigne, char **values, char **colNames) ;
		static int GetSimulationCallback(void* pReturnedSimulation, int nbLigne, char **values, char **colNames);
		static int GetResultCallback(void* pReturnedResult, int nbLigne, char **values, char **colNames);

		// Connexion a la base
		void Connect() throw(std::runtime_error);
		void Query(sqlite3_callback callback = 0,void *param = 0) throw(std::logic_error,std::runtime_error);
		int  QueryCount() throw(std::logic_error,std::runtime_error);
		void Disconnect() throw(std::logic_error);

		// Listes de pointeurs vers les instances déja crées
		std::set<Crossroad*> crossroads ;
		std::set<Road*> roads ;
		std::set<Simulation*> simulations ;
		std::set<Result*> results ;

};


#endif /* NETWORKENGINE_HPP_ */
