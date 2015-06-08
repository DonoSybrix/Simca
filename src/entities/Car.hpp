/*
 * Car.hpp
 *
 *  Created on: 13 avr. 2011
 *      Author: Axel GUILMIN
 */

#ifndef CAR_HPP_
#define CAR_HPP_

#include "Entity.hpp"
#include "../utils/other.hpp"

class Car : public Entity, public Drawable, public PhysicBody
{
    public:
        Car();
        ~Car();

        // Initialisation de l'element
        void Init();

        // Changement de la couleur
        void SetColor( std::string color );

        // Donne une couleur au hasard à la voiture
        void SetRandomColor();

        // Donne la distance par rapport au rond point
        void SetDistance( float distance );

        // Récupère la distance de la voiture
        float GetDistance() const;

        // Indique la route de sortie
        void SetExitRoad( unsigned int value );

        // Retourne la route de sortie
        float GetExitRoad() const;

        // Methode permettant la mise a jour de l'element
        void Update( float crossRoadWidth, int direction = 0 );

    private:

        // Couleur de la voiture
        std::string myColor;

        // Distance de la voiture
        float myDistance;

        // Route par laquelle sort la voiture
        unsigned int myExitRoad;

};

#endif /* CAR_HPP_ */
