////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "Data.hpp"
#include "../graphic/GraphicEngine.hpp"

////////////////////////////////////////////////////////////
/// Default constructor
////////////////////////////////////////////////////////////
Data::Data() : myDataName("No-Name")
{

}

////////////////////////////////////////////////////////////
/// Default destructor
////////////////////////////////////////////////////////////
Data::~Data()
{
    Clear();
}

////////////////////////////////////////////////////////////
/// Clear the map
////////////////////////////////////////////////////////////
void Data::Clear()
{
    std::cout << std::endl << std::endl << "---- Cleaning the map -----" << std::endl;
    std::cout << "- Before : " << myEntities.size() << std::endl;

    // Delete entities
    for(std::vector<Entity*>::iterator i = myEntities.begin(); i < myEntities.end(); i++)
    {
        if( (*i) != NULL )
        {
            delete (*i);
            (*i) = NULL;
        }
    }

    // Security
    if(!myEntities.empty())
         myEntities.clear();

    std::cout << "- After  : " << myEntities.size() << std::endl;
}

////////////////////////////////////////////////////////////
///
/// Load a simulation.
///
////////////////////////////////////////////////////////////
void Data::Load( std::string dataName )
{
    // Utile à la methode
    GraphicEngine *graphic = GraphicEngine::getInstance();
    sf::Vector2f roadPosition;
    Road *road = NULL;

    // Debut
    std::cout << "---- Loading the simulation ----" << std::endl;
    myDataName = dataName;

    // Chargements (TODO: Utiliser Network et BDD ici)
    Crossroad *crossroad = new Crossroad();
    crossroad->SetWidth( 150 );
    crossroad->Update();
    myEntities.push_back( crossroad );
    graphic->AddDrawable( crossroad );

    //@dono Exemple utilisation de Network, par id
    //Crossroad* crossroad = NetworkEngine::getInstance()->GetCrossroad(2) ;
    // Ou par nom
    //Crossroad* crossroad = NetworkEngine::getInstance()->GetCrossroad("toto") ;
    // Pour creer un nouveau
    //Crossroad *crossroad = new Crossroad();
    //int idCrossroad = NetworkEngine::getInstance()->SetCrossroad(crossroad) ;

    unsigned int nbRoute = 5;
    std::vector<int> carsTab;

    for( unsigned int i = 0; i < nbRoute; i++ )
    {
        road = new Road();
        road->SetRadius( 74 * i );
        roadPosition = RotateAround( road->GetWidth(), road->GetRadius(), sf::Vector2f( WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 ), crossroad->GetWidth() / 2 - 5 );
        road->SetPosition( roadPosition.x, roadPosition.y );
        road->SetCrossroad( crossroad );
        myEntities.push_back( road );
        myRoads.push_back( road );
        graphic->AddDrawable( road );
/*
        if( i == 1 )
        {
            // Ajout de voitures pour la route 2 (Tests)
            for( int j = 0; j < nbVoiture; j++ )
            {
                /// Création d'une voiture
                car = new Car();
                car->SetColor( "red" );
                car->Update();
                graphic->AddDrawable( car );

                /// Ajout de la voiture dans la route N°1
                road->AddCarIn( car );
            }
        }*/

        road->Update();
    }


    // Fin
    std::cout << "- " << myEntities.size() << " entities."<< std::endl;
}

////////////////////////////////////////////////////////////
///
/// Save a simulation.
///
////////////////////////////////////////////////////////////
void Data::Save()
{

}


////////////////////////////////////////////////////////////
///
/// Recuperation des entites
///
////////////////////////////////////////////////////////////
std::vector<Entity*>* Data::GetEntities()
{
    return &myEntities;
}

////////////////////////////////////////////////////////////
///
/// Recuperation des routes
///
////////////////////////////////////////////////////////////
std::vector<Road*>* Data::GetRoads()
{
    return &myRoads;
}
