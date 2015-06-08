////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "App.hpp"

////////////////////////////////////////////////////////////
/// Default constructor
////////////////////////////////////////////////////////////
App::App()
{
    /// Init engines.
    behavior	= BehaviorEngine::getInstance();
    graphic 	= GraphicEngine::getInstance();
    physic  	= PhysicEngine::getInstance();
    network 	= NetworkEngine::getInstance();

    /// Link engines.
    // Behavior
    behavior->Attach_GraphicEngine(graphic);
    behavior->Attach_PhysicEngine(physic);
    behavior->Attach_NetworkEngine(network);

    // Graphic
    graphic->Attach_BehaviorEngine(behavior);
    graphic->Attach_PhysicEngine(physic);
    graphic->Attach_NetworkEngine(network);

    // Physic
    physic->Attach_BehaviorEngine(behavior);
    physic->Attach_GraphicEngine(graphic);
    physic->Attach_NetworkEngine(network);

    // Network
    network->Attach_BehaviorEngine(behavior);
    network->Attach_GraphicEngine(graphic);
    network->Attach_PhysicEngine(physic);
}

////////////////////////////////////////////////////////////
/// Default destructor
////////////////////////////////////////////////////////////
App::~App()
{
    delete behavior;
    delete graphic;
    delete physic;
    delete network;
}

////////////////////////////////////////////////////////////
///
///    Heart of the application.
///    The main loop.
///
////////////////////////////////////////////////////////////
void App::Run()
{

    while( behavior->IsRunning() )
    {
    	network->Frame();
        behavior->Frame();
        physic->Frame();
        graphic->Frame();
    }
}
