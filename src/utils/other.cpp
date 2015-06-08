/*
 * other.cpp
 *
 *  Created on: 3 mai 2011
 *      Author: Axel GUILMIN
 */

#include "other.hpp"

///////////////////////////////////////
/// Positionne un objet suivant son angle et le rayon de l'aobjet en question
/// @param Entity entity
/// @param Sf::Vector2f position - Position du point
/// @param Sf:
///////////////////////////////////////
sf::Vector2f RotateAround( float entityWidth, float entityRadius, sf::Vector2f positionPoint, float diameterPoint )
{
    float radian    = -3.14159265 * entityRadius / 180;
    float positionX = cos(radian) * ( diameterPoint + entityWidth / 2 );
    float positionY = sin(radian) * ( diameterPoint + entityWidth / 2 );

    positionX += positionPoint.x;
    positionY += positionPoint.y;

    return sf::Vector2f( positionX, positionY );
}
