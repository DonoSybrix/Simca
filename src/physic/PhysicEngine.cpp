////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "PhysicEngine.hpp"

////////////////////////////////////////////////////////////
/// Default constructor
////////////////////////////////////////////////////////////
PhysicEngine::PhysicEngine()
{

}

////////////////////////////////////////////////////////////
/// Default destructor
////////////////////////////////////////////////////////////
PhysicEngine::~PhysicEngine()
{

}

////////////////////////////////////////////////////////////
///
///    Heart of the physic engine.
///    Do actions for all elements.
///
////////////////////////////////////////////////////////////
void PhysicEngine::Frame()
{
    float frameTime = graphic->GetWindow()->GetFrameTime();

    // Bouge les objets
    for(std::vector<PhysicBody*>::iterator i = myBodies.begin(); i < myBodies.end(); i++)
    {
        sf::Vector2f velocity = (*i)->GetVelocity();
        sf::Vector2f position = (*i)->GetPosition();

        position.x += velocity.x * frameTime * behavior->GetMySimulationSpeed();
        position.y += velocity.y * frameTime * behavior->GetMySimulationSpeed();


        (*i)->SetPosition( position );
    }
}
////////////////////////////////////////////////////////////
///
///    Add an object in the physicable list.
///
////////////////////////////////////////////////////////////
void PhysicEngine::AddBody( PhysicBody *body)
{
    myBodies.push_back( body );
}
