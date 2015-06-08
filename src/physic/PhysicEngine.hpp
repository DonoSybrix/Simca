////////////////////////////////////////////////////////////
//
// Iridium
// Copyright (C) 2011 Orhan Donovan ( sybrix44@gmail.com )
//
// - Author : Orhan Donovan.
// - Create : 04/02/2011.
// - Desc.  : Main of Physic Engine
//
////////////////////////////////////////////////////////////

#ifndef PHYSICENGINE_HPP
#define PHYSICENGINE_HPP

#include "../engine/Engine.hpp"
#include "../graphic/GraphicEngine.hpp"

#include "../utils/Singleton.hpp"

#include "type/PhysicBody.hpp"

class PhysicEngine : public Engine, public Singleton<PhysicEngine>
{
    // Singleton
    friend class Singleton<PhysicEngine>;

    public:
        // Constructor / Destructor.
        PhysicEngine();
        virtual ~PhysicEngine();

        // Main of the physic engine.
        virtual void Frame();

        // Ajoute un element physique au moteur
        void AddBody( PhysicBody *body );

    public:

        // All entities who will be collidable
        std::vector<PhysicBody*> myBodies;
};

#endif

