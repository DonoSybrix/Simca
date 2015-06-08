/*
 * Result.cpp
 *
 *  Created on: 17 avr. 2011
 *      Author: axel
 */

#include "Result.hpp"

////////////////////////////////////////////////////////////
// Default constructor
////////////////////////////////////////////////////////////
Result::Result()
{
	this->idResultatArtere = 0 ;
}
////////////////////////////////////////////////////////////
/// Full constructor
////////////////////////////////////////////////////////////
Result::Result(Road* road, Simulation* simulation, unsigned int tempsMoyen, unsigned int tempsCumul, unsigned int tempsMax, unsigned int tempsEcartType, float deuxFeux )
{
	this->idResultatArtere = 0 ;
	this->SetTempsMoyen(tempsMoyen) ;
	this->SetTempsCumul(tempsCumul) ;
	this->SetTempsMax(tempsMax) ;
	this->SetTempsEcartType(tempsEcartType) ;
	this->SetDeuxFeux(deuxFeux) ;
	this->SetRoad(road);
	this->SetSimulation(simulation);
}
////////////////////////////////////////////////////////////
// Default Destructor
////////////////////////////////////////////////////////////
Result::~Result()
{

}
////////////////////////////////////////////////////////////
// Accesseur
////////////////////////////////////////////////////////////
Road *Result::GetRoad() const
{
	return road;
}

float Result::GetDeuxFeux() const
{
	return deuxFeux;
}

unsigned int Result::GetIdResultatArtere() const
{
	return idResultatArtere;
}

Simulation *Result::GetSimulation() const
{
	return simulation;
}

unsigned int Result::GetTempsMoyen() const
{
	return tempsMoyen;
}

unsigned int Result::GetTempsCumul() const
{
	return tempsCumul;
}

unsigned int Result::GetTempsEcartType() const
{
	return tempsEcartType;
}

unsigned int Result::GetTempsMax() const
{
	return tempsMax;
}

void Result::SetRoad(Road *road)
{
	this->road= road;
}

void Result::SetDeuxFeux(float deuxFeux)
{
	this->deuxFeux = deuxFeux;
}

void Result::SetIdResultatArtere(unsigned int idResultatArtere)
{
	this->idResultatArtere = idResultatArtere;
}

void Result::SetSimulation(Simulation *simulation)
{
	this->simulation = simulation;
}

void Result::SetTempsMoyen(unsigned int tempsMoyen)
{
	this->tempsMoyen = tempsMoyen;
}

void Result::SetTempsCumul(unsigned int tempsCumul)
{
	this->tempsCumul = tempsCumul;
}

void Result::SetTempsEcartType(unsigned int tempsEcartType)
{
	this->tempsEcartType = tempsEcartType;
}

void Result::SetTempsMax(unsigned int tempsMax)
{
	this->tempsMax = tempsMax;
}
