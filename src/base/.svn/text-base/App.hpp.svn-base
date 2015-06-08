////////////////////////////////////////////////////////////
//
// Iridium
// Copyright (C) 2011 Orhan Donovan ( dono.orhan@gmail.com )
//
// - Author : Orhan Donovan.
// - Create : 04/02/2011.
// - Desc.  : Heart of app, link engine and loop is here !
//
////////////////////////////////////////////////////////////

#ifndef APP_HPP
#define APP_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "../utils/library.hpp"
#include "../behavior/BehaviorEngine.hpp"
#include "../graphic/GraphicEngine.hpp"
#include "../physic/PhysicEngine.hpp"
#include "../network/NetworkEngine.hpp"

class App
{
    public:
        // Constructor / Destructor.
        App();
        ~App();

        // Main loop of the game.
        void Run();

    private:
        // Engines.
        BehaviorEngine	*behavior;
        GraphicEngine 	*graphic;
        PhysicEngine  	*physic;
        NetworkEngine  	*network;
};

#endif
