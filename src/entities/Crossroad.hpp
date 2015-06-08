////////////////////////////////////////////////////////////
//
// Simca
// Copyright (C) 2011 Orhan Donovan ( dorhan@epsi.fr )
//
// - Author : Orhan Donovan.
// - Desc.  : A Crossroad
//
////////////////////////////////////////////////////////////


#ifndef CROSSROAD_HPP_
#define CROSSROAD_HPP_

#include "Entity.hpp"
class Road;
class Car;

class Crossroad : public Entity, public Drawable, public PhysicBody
{
    public:

        // Construtor / Destructor
        Crossroad();
        Crossroad(std::string nom, unsigned int rayon = 0);
        ~Crossroad();

        // Initialisation de l'element
        void Init();

        // Surcharge de la methode "Draw" de Drawables
        void Draw( sf::RenderWindow &myWindow, float elapsedTime );

        // Mise à jour de l'entité
        void Update();

        // Accesseurs
        void SetNom( const std::string name );
        std::string GetNom() const;
        void SetIdCarrefour( const unsigned int id );
        unsigned int GetIdCarrefour() const;

        // Liste des id road associées au rond-point
        std::set<int> roads;
        std::set<int> simulations;

    private:
        // Pas de texture pour cet element, un dessin basique.
        sf::Shape myShape;

        // Donnees persistantes
        unsigned int idCarrefour;
        std::string nom ;
        //int rayon = myWidth / 2

        // Les voitures actuellements sur le rond-point, et la route ou elle vont sortir
        std::map<Road*,Car*> myCars ;


};

#endif /* CROSSROAD_HPP_ */
