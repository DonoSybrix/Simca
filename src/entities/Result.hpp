/*
 * Result.hpp
 *
 *  Created on: 17 avr. 2011
 *      Author: Axel GUILMIN
 */

#ifndef RESULT_HPP_
#define RESULT_HPP_

#include "Entity.hpp"

class Road;
class Simulation;

class Result : public Entity
{
    public:
        Result();
        Result(Road* road, Simulation* simulation, unsigned int tempsMoyen=0, unsigned int tempsCumul=0, unsigned int tempsMax=0, unsigned int tempsEcartType=0, float deuxFeux=0 );
        ~Result();

        // Accesseurs
		Road *GetRoad() const;
		float GetDeuxFeux() const;
		unsigned int GetIdResultatArtere() const;
		Simulation *GetSimulation() const;
		unsigned int GetTempsMoyen() const;
		unsigned int GetTempsCumul() const;
		unsigned int GetTempsEcartType() const;
		unsigned int GetTempsMax() const;
		void SetRoad(Road *artere);
		void SetDeuxFeux(float deuxFeux);
		void SetIdResultatArtere(unsigned int idResultatArtere);
		void SetSimulation(Simulation *simulation);
		void SetTempsMoyen(unsigned int tempsMoyen);
		void SetTempsCumul(unsigned int tempsCumul);
		void SetTempsEcartType(unsigned int tempsEcartType);
		void SetTempsMax(unsigned int tempsMax);

private:

        // Données persistantes
        unsigned int idResultatArtere;
        unsigned int tempsMoyen;
        unsigned int tempsCumul;
        unsigned int tempsMax;
        unsigned int tempsEcartType;
        float deuxFeux;
        Road* road;
        Simulation* simulation;
};

#endif /* RESULT_HPP_ */
