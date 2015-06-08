////////////////////////////////////////////////////////////
//
// Simca
// Copyright (C) 2011 Orhan Donovan ( dorhan@epsi.fr )
//
// - Author : Orhan Donovan.
// - Desc.  : A Crossroad
//
////////////////////////////////////////////////////////////

#ifndef ROAD_HPP_
#define ROAD_HPP_

#include "Entity.hpp"
#include "Car.hpp"
#include "Crossroad.hpp"
#include "TrafficLights.hpp"
#include "../utils/other.hpp"

class Road : public Entity, public Drawable, public PhysicBody
{
    public:
        Road();
        Road(std::string nom, Crossroad* crossroad, int debit=0, float angle=0.0, int dureeFeuVert=0, int positionFeu=0, int delaiAvantSuivant=0 );
        ~Road();

        // Initialisation de l'element
        void Init();

        // Test
        void Draw( sf::RenderWindow &myWindow, float elapsedTime );

        // Enleve la voiture de devant dans la file
        void PopCar();

        // Methode permettant la mise à jour de l'element
        void Update();

        // Accesseurs
        Crossroad *GetCrossroad() const;
        unsigned int GetDebit() const;
        unsigned int GetDelaiAvantSuivant() const;
        unsigned int GetDureeFeuVert() const;
        unsigned int GetIdArtere() const;
        std::string GetNom() const;
        int GetPositionFeu() const;
        void SetCrossroad(Crossroad *crossroad);
        void SetDebit(unsigned int debit);
        void SetDelaiAvantSuivant(unsigned int delaiAvantSuivant);
        void SetDureeFeuVert(unsigned int dureeFeuVert);
        void SetIdArtere(unsigned int idArtere);
        void SetNom(std::string nom);
        void SetPositionFeu(int positionFeu);
        void AddCarIn(Car* car);
        void AddCarOut(Car* car);
        std::queue<Car*>* GetCarIn();
        TrafficLights* GetTrafficLight();

        // Met à jour la position des voitures
        void UpdateCars();

    private:
        // Donnees persistantes
        unsigned int idArtere;
        std::string nom;
        unsigned int debit;
        unsigned int dureeFeuVert;
        int positionFeu;
        unsigned int delaiAvantSuivant;
        // pointeur vers l'objet carrefour correspondant
        Crossroad* crossroad;
        std::queue<Car*> carsIn ;
        std::queue<Car*> carsOut ;

        TrafficLights myTrafficLight;
};

#endif /* ROAD_HPP_ */
