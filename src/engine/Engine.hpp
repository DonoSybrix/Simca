////////////////////////////////////////////////////////////
//
// Iridium
// Copyright (C) 2011 Orhan Donovan ( dono.orhan@gmail.com )
//
// - Author : Orhan Donovan.
// - Create : 04/02/2011.
// - Desc.  : Link Engines
//
////////////////////////////////////////////////////////////

#ifndef ENGINE_HPP
#define ENGINE_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

class BehaviorEngine;
class GraphicEngine;
class PhysicEngine;
class NetworkEngine;

class Engine
{
    public:
        // Virtual destructor.
        virtual ~Engine();

        virtual void Frame() = 0;

        // Attach engines
        void Attach_BehaviorEngine(BehaviorEngine *b){behavior = b;}
        void Attach_GraphicEngine(GraphicEngine *g){graphic = g;}
        void Attach_PhysicEngine(PhysicEngine *p){physic = p;}
        void Attach_NetworkEngine(NetworkEngine *n){network = n;}

    protected:
        BehaviorEngine*behavior;
        GraphicEngine *graphic;
        PhysicEngine  *physic;
        NetworkEngine *network;
};

#endif
