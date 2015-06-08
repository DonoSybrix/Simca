/*
 * Simulation.hpp
 *
 *  Created on: 16 avr. 2011
 *      Author: Axel GUILMIN
 */

#ifndef SIMULATION_HPP_
#define SIMULATION_HPP_

#include "Entity.hpp"
class Crossroad;

class Simulation : public Entity
{
    public:
		// Constructeur
		Simulation();
		Simulation(std::string nom, Crossroad* crossroad, unsigned int dateHeureDeb=0, unsigned int dateHeureFin=0 );
		// Destructeur
		~Simulation();

		// Accesseurs
		unsigned int GetIdSimulation() const;
		Crossroad *GetCrossroad() const;
		unsigned int GetDateHeureDeb() const;
		unsigned int GetDateHeureFin() const;
		std::string GetNom() const;
		void SetIdSimulation(unsigned int id);
		void SetCrossroad(Crossroad *crossroad);
		void SetDateHeureDeb(unsigned int dateHeureDeb);
		void SetDateHeureFin(unsigned int dateHeureFin);
		void SetNom(std::string nom);

    private:
		unsigned int idSimulation;
		std::string nom;
		unsigned int dateHeureDeb;
		unsigned int dateHeureFin;
		Crossroad* crossroad;
};

#endif /* SIMULATION_HPP_ */
