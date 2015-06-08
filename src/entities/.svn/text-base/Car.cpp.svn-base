#include "Car.hpp"


////////////////////////////////////////////////////////////
/// Default constructor
////////////////////////////////////////////////////////////
Car::Car()
{
    Init();
}


////////////////////////////////////////////////////////////
/// Default destructor
////////////////////////////////////////////////////////////
Car::~Car()
{

}



////////////////////////////////////////////////////////////
/// Initialisation
////////////////////////////////////////////////////////////
void Car::Init()
{
    // Default dimensions
    myWidth     = 48;
    myHeight    = 33;
    myDistance  = 600;
    isDraggable = false;
    myExitRoad  = 0;

     // Get the sprite
    ImageManager *myImageManager = ImageManager::getInstance();
    sf::Image* crossroadTexture = myImageManager->GetImage("../data/textures/cars.png");
    crossroadTexture->SetSmooth(false); // Evite une bordure bizarre sur les textures

    if ( crossroadTexture != NULL )
        mySprite.SetImage( *crossroadTexture );

    if ( crossroadTexture != NULL )
        myAnimations.SetSprite( &mySprite );

    // Sprite configuration
    mySprite.SetCenter( myWidth / 2, myHeight / 2 );
    mySprite.SetSubRect( sf::IntRect( 0, 0, myWidth, myHeight) );
}


////////////////////////////////////////////////////////////
/// Changement de la couleur
////////////////////////////////////////////////////////////
void Car::SetColor( std::string color )
{
    int x = 0;

    if( color == "black" )
        x = 0;
    else if( color == "blue" )
        x = myWidth;
    else if( color == "red" )
        x = myWidth * 2;
    else if( color == "purple" )
        x = myWidth * 3;
    else if( color == "green" )
        x = myWidth * 4 - 2;
    else if( color == "red_2" )
        x = myWidth * 5 - 3;
    else if( color == "blue_2" )
        x = myWidth * 6;
    else
        x = 0;

    myColor = color;
    mySprite.SetSubRect( sf::IntRect( x, 0, myWidth + x, myHeight ) );
}

////////////////////////////////////////////////////////////
/// Donne une couleru au hasard
////////////////////////////////////////////////////////////
void Car::SetRandomColor()
{
    unsigned int carColor = sf::Randomizer::Random(0, 6);

    std::vector<std::string> carColorList;
    carColorList.push_back("red");
    carColorList.push_back("blue");
    carColorList.push_back("black");
    carColorList.push_back("purple");
    carColorList.push_back("green");
    carColorList.push_back("red_2");
    carColorList.push_back("blue_2");

    myColor = carColorList.at( carColor );
    SetColor( myColor );
}

////////////////////////////////////////////////////////////
/// Change la distance par rapport au rond point
////////////////////////////////////////////////////////////
void Car::SetDistance( float distance )
{
    myDistance = distance;
}

////////////////////////////////////////////////////////////
/// Récupère la distance de la voiture
////////////////////////////////////////////////////////////
float Car::GetDistance() const
{
    return myDistance;
}

////////////////////////////////////////////////////////////
/// Indique la route de sortie
////////////////////////////////////////////////////////////
void Car::SetExitRoad( unsigned int value )
{
    myExitRoad = value;
}

////////////////////////////////////////////////////////////
/// Retourne la route de sortie
////////////////////////////////////////////////////////////
float Car::GetExitRoad() const
{
    return myExitRoad;
}

////////////////////////////////////////////////////////////
/// Mise a jour du sprite
////////////////////////////////////////////////////////////
void Car::Update( float crossRoadWidth, int direction )
{
    mySprite.SetRotation( myRadius + direction );

    sf::Vector2f position = RotateAround( myPosition.x, myRadius, sf::Vector2f( WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 ), (crossRoadWidth / 2 + 35 ) );
    mySprite.SetPosition( position  );
}
