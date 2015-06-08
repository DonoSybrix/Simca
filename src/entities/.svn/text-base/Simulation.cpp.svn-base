/*
 * Simulation.cpp
 *
 *  Created on: 16 avr. 2011
 *      Author: Axel GUILMIN
 */

#include "Simulation.hpp"

////////////////////////////////////////////////////////////
/// Default constructor
////////////////////////////////////////////////////////////
Simulation::Simulation()
{

}

////////////////////////////////////////////////////////////
/// Full constructor
////////////////////////////////////////////////////////////
Simulation::Simulation(std::string nom, Crossroad* crossroad, unsigned int dateHeureDeb, unsigned int dateHeureFin )
{
	this->SetNom(nom);
	this->SetDateHeureDeb(dateHeureDeb) ;
	this->SetDateHeureFin(dateHeureFin) ;
	this->SetCrossroad(crossroad);
}

////////////////////////////////////////////////////////////
/// Default destructor
////////////////////////////////////////////////////////////
Simulation::~Simulation()
{

}

////////////////////////////////////////////////////////////
/// Accesseurs
////////////////////////////////////////////////////////////
unsigned int Simulation::GetIdSimulation() const
{
    return idSimulation;
}

Crossroad *Simulation::GetCrossroad() const
{
    return crossroad;
}

unsigned int Simulation::GetDateHeureDeb() const
{
    return dateHeureDeb;
}

unsigned int Simulation::GetDateHeureFin() const
{
    return dateHeureFin;
}

std::string Simulation::GetNom() const
{
    return nom;
}

void Simulation::SetIdSimulation(unsigned int id)
{
    this->idSimulation = id;
}

void Simulation::SetCrossroad(Crossroad *crossroad)
{
    this->crossroad = crossroad;
}

void Simulation::SetDateHeureDeb(unsigned int dateHeureDeb)
{
    this->dateHeureDeb = dateHeureDeb;
}

void Simulation::SetDateHeureFin(unsigned int dateHeureFin)
{
    this->dateHeureFin = dateHeureFin;
}

void Simulation::SetNom(std::string nom)
{
    this->nom = nom;
}
