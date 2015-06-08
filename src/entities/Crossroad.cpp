#include "Crossroad.hpp"


////////////////////////////////////////////////////////////
/// Default constructor
////////////////////////////////////////////////////////////
Crossroad::Crossroad()
{
    // Initialisation du carrefour
    Init();
}

////////////////////////////////////////////////////////////
/// Full constructor
////////////////////////////////////////////////////////////
Crossroad::Crossroad(std::string nom, unsigned int rayon)
{
	this->SetNom(nom);
	Entity::SetWidth(rayon*2);
	Entity::SetHeight(rayon*2);

    // Initialisation du carrefour
    Init();
}

////////////////////////////////////////////////////////////
/// Default destructor
////////////////////////////////////////////////////////////
Crossroad::~Crossroad()
{

}


////////////////////////////////////////////////////////////
/// Initialisation
////////////////////////////////////////////////////////////
void Crossroad::Init()
{
    // Default dimensions
    myWidth     = myHeight = 436;
    isDraggable = false;

    // Creation
    myShape = sf::Shape::Circle( WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, myWidth / 2, sf::Color( 122, 122, 122 ) );
}


////////////////////////////////////////////////////////////
/// Surcharge de la methode Draw
////////////////////////////////////////////////////////////
void Crossroad::Draw( sf::RenderWindow &myWindow, float elapsedTime )
{
    myWindow.Draw( myShape );
}

////////////////////////////////////////////////////////////
/// Mise à jour de l'entité
////////////////////////////////////////////////////////////
void Crossroad::Update()
{
	myShape.SetScale( myWidth, myWidth );
	myShape = sf::Shape::Circle( WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, myWidth / 2, sf::Color( 122, 122, 122 ) );
}

////////////////////////////////////////////////////////////
/// Accesseurs
////////////////////////////////////////////////////////////
void Crossroad::SetNom( const std::string name )
{
	this->nom = name;
}

std::string Crossroad::GetNom() const
{
	return this->nom;
}

void Crossroad::SetIdCarrefour( const unsigned int id )
{
	this->idCarrefour = id;
}
unsigned int Crossroad::GetIdCarrefour() const
{
	return this->idCarrefour;
}
