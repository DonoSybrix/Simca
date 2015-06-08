#include "TrafficLights.hpp"

////////////////////////////////////////////////////////////
/// Default constructor
////////////////////////////////////////////////////////////
TrafficLights::TrafficLights()
{
    myShapeBox   = sf::Shape::Rectangle( 0, 0, 30, 30, sf::Color( 0, 0, 0 ) );
    myShapeLight = sf::Shape::Circle( WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 10, sf::Color( 0, 255, 0, 30 ) );
    mySwitchDelay = 3;
    myDelay       = 5;
    isGreen       = false;
}

////////////////////////////////////////////////////////////
/// Default destructor
////////////////////////////////////////////////////////////
TrafficLights::~TrafficLights()
{

}

////////////////////////////////////////////////////////////
/// Surcharge de la methode Draw
////////////////////////////////////////////////////////////
void TrafficLights::Draw( sf::RenderWindow &myWindow, float elapsedTime )
{
    myWindow.Draw( myShapeLight );
    myWindow.Draw( myShapeBox );
}

////////////////////////////////////////////////////////////
/// Indique le temps d'une couleur
////////////////////////////////////////////////////////////
void TrafficLights::SetDelay( unsigned int delay )
{
    myDelay = delay;
}

////////////////////////////////////////////////////////////
/// Indique le temps entre changement de couleur
////////////////////////////////////////////////////////////
void TrafficLights::SetSwitchDelay( unsigned int delay )
{
    mySwitchDelay = delay;
}

////////////////////////////////////////////////////////////
/// Change l'état du feu
////////////////////////////////////////////////////////////
void TrafficLights::SetState( bool state )
{
    isGreen = state;
}

////////////////////////////////////////////////////////////
/// Retourne l'état du feu
////////////////////////////////////////////////////////////
bool TrafficLights::GetState() const
{
    return isGreen;
}

////////////////////////////////////////////////////////////
/// Retourne le temps que le feu reste allumé
////////////////////////////////////////////////////////////
unsigned int TrafficLights::GetMyDelay() const
{
    return myDelay;
}

////////////////////////////////////////////////////////////
/// Retourne le temps que le feu reste eteint avant de switcher
////////////////////////////////////////////////////////////
unsigned int TrafficLights::GetMySwitchDelay() const
{
    return mySwitchDelay;
}

////////////////////////////////////////////////////////////
/// Mise à jour du sprite
////////////////////////////////////////////////////////////
void TrafficLights::Update( float crossRoadRadius, float roadRadius )
{
    sf::Vector2f position = RotateAround( 10, roadRadius, sf::Vector2f( WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 ), crossRoadRadius );

    sf::Color color;
    if( isGreen ) {
        color = sf::Color( 0, 255, 0, 130 );
    }
    else{
        color = sf::Color( 255, 0, 0, 130 );
    }

    myShapeBox   = sf::Shape::Rectangle( position.x-10, position.y-10, position.x+10, position.y+10, sf::Color( 0, 0, 0 ) );
    myShapeBox.SetCenter( sf::Vector2f( position.x, position.y ) );
    myShapeBox.SetRotation( roadRadius );
    myShapeBox.SetPosition( sf::Vector2f( position.x, position.y ) );

    position = RotateAround( 28, roadRadius, sf::Vector2f( WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 ), crossRoadRadius );
    myShapeLight = sf::Shape::Circle( position.x, position.y, 10, color );

}
