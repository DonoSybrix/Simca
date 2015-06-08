////////////////////////////////////////////////////////////
//
// Simca
// Copyright (C) 2011 Orhan Donovan ( sybrix44@gmail.com )
//
// - Author : Orhan Donovan.
// - Create : 04/02/2011.
// - Desc.  : Other
//
////////////////////////////////////////////////////////////

#ifndef OTHER_HPP
#define OTHER_HPP

#include "library.hpp"
#include <SFML/Graphics.hpp>

template<typename T> int toInt( const T & value );
template<typename T> float toFloat( const T & value );
template<typename T> std::string toString( const T & value );
template<typename T> std::string secondsToTime( const T & seconds );
template<typename T> unsigned int timeToSeconds( const T & time );


/* Si on met le contenu de other.cpp ici (sauf la premiere ligne)
 * et bah ca marche !!!!
 * Fuuuuuu
 */

 // Convertion vers int
template<typename T>
int toInt( const T & value )
{
    // créer un flux à partir de la chaîne à convertir
    std::istringstream iss( value );
    // convertir en un int
    int nombre;
    iss >> nombre;
    return nombre;
}

// Convertion vers float
template<typename T>
float toFloat( const T & value )
{
	std::istringstream iss( value );
	float f;
	iss >> f;
	return f;
}

// Convertir n'importe quel type d'objets en string
// http://cpp.developpez.com/faq/cpp/?page=strings#STRINGS_convertform
template<typename T>
std::string toString( const T & value )
{
    // utiliser un flux de sortie pour créer la chaîne
    std::ostringstream oss;
    // écrire la valeur dans le flux
    oss << value;
    // renvoyer une string
    return oss.str();
}

// Convertir un nombre de secondes (BDD) en hh:mm:ss
template<typename T>
std::string secondsToTime(const T & seconds)
{
	std::string time;
	std::string hh,mm,ss;

	// Heures
	hh = toString(seconds / 3600);

	// Minutes
	mm = toString((seconds%3600) / 60);
	if(toInt(mm)<10) // Forcer l'affichage sur deux digit
		mm = "0" + mm ;

	// Secondes
	ss = toString(seconds%3600%60);
	if(toInt(ss)<10) // Forcer l'affichage sur deux digit
		ss = "0" + ss;


	if(hh=="0")
		time = mm + ":" + ss;
	else // hh:mm:ss
		time = hh + ":" + mm + ":" + ss;

	return time;
}

template<typename T>
unsigned int timeToSeconds(const T & time)
{
	unsigned int seconds;

	// ss
	seconds = toInt(time.substr(time.size()-2,2));
	// mm
	unsigned int mm = toInt(time.substr(time.size()-5,2));
	seconds += mm * 60 ;
	// hh
	if(mm>0)
		seconds += toInt(time.substr(0,time.find(":"))) * 3600;

	return seconds;
}

// Positionne un objet par rapport à un point suivant son angle et le rayon du point
sf::Vector2f RotateAround( float entityWidth, float entityRadius, sf::Vector2f position, float diameterPoint );


// Destroy any pointer ( Developpez.com )
struct Delete
{
    template <class T> void operator ()(T*& p) const
    {
        delete p;
        p = NULL;
    }
};

#endif // OTHER_HPP
