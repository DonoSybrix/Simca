////////////////////////////////////////////////////////////
//
// Simca
// Copyright (C) 2011 Orhan Donovan ( sybrix44@gmail.com )
//
// - Author : Orhan Donovan.
// - Create : 04/02/2011.
// - Desc.  : PhysicBody, Element de type physique
//
////////////////////////////////////////////////////////////

#ifndef H_PHYSICBODY
#define H_PHYSICBODY

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include "../../utils/library.hpp"

class PhysicBody
{
    public:

        // Constructor / Destructor.
        PhysicBody();
        ~PhysicBody();

        // Change la vitesse de l'objet
        void SetVelocity( sf::Vector2f velocity );

        // Get myVelocity
        sf::Vector2f GetVelocity() const;

        // Change la position de l'objet
        void SetPosition( sf::Vector2f position );

        // Change la position de l'objet
        void SetPosition( float x, float y );

        // Retourne l'acceleration de l'objet
        sf::Vector2f GetPosition() const;


    protected:

        sf::Vector2f myPosition;

        sf::Vector2f myVelocity;

};

#endif // H_DRAWABLE

