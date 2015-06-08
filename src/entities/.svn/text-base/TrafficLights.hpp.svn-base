////////////////////////////////////////////////////////////
//
// Simca
// Copyright (C) 2011 Orhan Donovan ( dorhan@epsi.fr )
//
// - Author : Orhan Donovan.
// - Desc.  : Traffic Lights
//
////////////////////////////////////////////////////////////


#ifndef TRAFFICLIGHTS_HPP_
#define TRAFFICLIGHTS_HPP_

#include "Entity.hpp"
#include "../utils/other.hpp"

class TrafficLights: public Entity, public Drawable, public PhysicBody
{
    public:

        // Construtor / Destructor
        TrafficLights();
        ~TrafficLights();

        void SetDelay( unsigned int delay );
        void SetSwitchDelay( unsigned int delay );
        void Draw( sf::RenderWindow &myWindow, float elapsedTime );
        void Update( float crossRoadRadius, float roadRadius  );

        bool GetState() const;
        void SetState( bool state );

        unsigned int GetMyDelay() const;
        unsigned int GetMySwitchDelay() const;

    private:

        unsigned int myDelay;
        unsigned int mySwitchDelay;
        sf::Shape myShapeLight;
        sf::Shape myShapeBox;
        bool isGreen; // 0 => Rouge, 1 => Vert
};

#endif /* TRAFFICLIGHTS_HPP_ */

