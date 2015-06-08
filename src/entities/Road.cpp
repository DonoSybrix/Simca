#include "Road.hpp"

////////////////////////////////////////////////////////////
/// Default constructor
////////////////////////////////////////////////////////////
Road::Road()
{
    Init();
}

////////////////////////////////////////////////////////////
/// Full constructor
////////////////////////////////////////////////////////////
Road::Road(std::string nom, Crossroad* crossroad, int debit, float angle, int dureeFeuVert, int positionFeu, int delaiAvantSuivant)
{
	this->idArtere = 0 ;
	this->SetNom(nom);
	this->SetDebit(debit) ;
	this->SetRadius(angle);
	this->SetDureeFeuVert(dureeFeuVert);
	this->SetPositionFeu(positionFeu);
	this->SetDelaiAvantSuivant(delaiAvantSuivant) ;

	this->SetCrossroad(crossroad);

    Init();
}

////////////////////////////////////////////////////////////
/// Default destructor
////////////////////////////////////////////////////////////
Road::~Road()
{

}


////////////////////////////////////////////////////////////
/// Initialisation
////////////////////////////////////////////////////////////
void Road::Init()
{
    // Default dimensions
    myWidth  = 600;
    myHeight = 80;

     // Get the sprite
    ImageManager *myImageManager = ImageManager::getInstance();
    sf::Image* crossroadTexture = myImageManager->GetImage("../data/textures/road.png");
    crossroadTexture->SetSmooth(true); // Evite une bordure bizarre sur les textures

    if ( crossroadTexture != NULL )
        mySprite.SetImage( *crossroadTexture );

    if ( crossroadTexture != NULL )
        myAnimations.SetSprite( &mySprite );

    // Sprite configuration
    mySprite.SetCenter( myWidth / 2, myHeight / 2 );
    mySprite.SetPosition( myPosition  );
    mySprite.SetRotation( myRadius );
    mySprite.FlipX( true );
}


////////////////////////////////////////////////////////////
/// Mise a jour du sprite
////////////////////////////////////////////////////////////
void Road::Update()
{
    // Mise à jour de la position suivant le rond poind
    sf::Vector2f roadPosition = RotateAround( myWidth, myRadius, sf::Vector2f( WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 ), crossroad->GetWidth() / 2 - 5 );

    mySprite.SetRotation( myRadius );
    mySprite.SetPosition( roadPosition  );

    myTrafficLight.SetPosition( myPosition.x, myPosition.y );
    myTrafficLight.Update( crossroad->GetWidth() / 2, myRadius );
    UpdateCars();
}


////////////////////////////////////////////////////////////
/// Surcharge de la methode Draw
////////////////////////////////////////////////////////////
void Road::Draw( sf::RenderWindow &myWindow, float elapsedTime )
{
    Drawable::Draw( myWindow, elapsedTime ) ;
    myTrafficLight.Draw( myWindow, elapsedTime );
}

////////////////////////////////////////////////////////////
/// Accesseurs
////////////////////////////////////////////////////////////
Crossroad *Road::GetCrossroad() const
{
  return crossroad;
}

unsigned int Road::GetDebit() const
{
  return debit;
}

unsigned int Road::GetDelaiAvantSuivant() const
{
  return delaiAvantSuivant;
}

unsigned int Road::GetDureeFeuVert() const
{
  return dureeFeuVert;
}

unsigned int Road::GetIdArtere() const
{
  return idArtere;
}

std::string Road::GetNom() const
{
  return nom;
}

int Road::GetPositionFeu() const
{
  return positionFeu;
}

void Road::SetCrossroad(Crossroad *crossroad)
{
  this->crossroad = crossroad;
}

void Road::SetDebit(unsigned int debit)
{
  this->debit = debit;
}

void Road::SetDelaiAvantSuivant(unsigned int delaiAvantSuivant)
{
  this->delaiAvantSuivant = delaiAvantSuivant;
}

void Road::SetDureeFeuVert(unsigned int dureeFeuVert)
{
  this->dureeFeuVert = dureeFeuVert;
}

void Road::SetIdArtere(unsigned int idArtere)
{
  this->idArtere = idArtere;
}

void Road::SetNom(std::string nom)
{
  this->nom = nom;
}

void Road::SetPositionFeu(int positionFeu)
{
  this->positionFeu = positionFeu;
}

void Road::AddCarIn( Car* car )
{
    carsIn.push( car );
}

std::queue<Car*>* Road::GetCarIn()
{
    return &carsIn;
}

TrafficLights* Road::GetTrafficLight()
{
    return &myTrafficLight;
}

void Road::PopCar()
{
    carsIn.pop();
}

void Road::UpdateCars()
{
    // Copie la queuee dans un vector
    std::vector<Car*> tempCarsList;
    while( !carsIn.empty() )
    {
        tempCarsList.push_back( carsIn.front() );
        carsIn.pop();
    }

    unsigned int carPosition = 0;
    std::vector<Car*>::iterator i;
    for( i = tempCarsList.begin(); i < tempCarsList.end(); i++ )
    {
        (*i)->SetRadius( myRadius );
        (*i)->Update( crossroad->GetWidth() );
        carsIn.push( (*i) );
        carPosition++;
    }
}
