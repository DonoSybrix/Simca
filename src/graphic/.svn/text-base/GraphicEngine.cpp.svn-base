////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "GraphicEngine.hpp"

////////////////////////////////////////////////////////////
/// Default constructor
////////////////////////////////////////////////////////////
GraphicEngine::GraphicEngine() : myCamera( myWindow.GetDefaultView() )
{
    myWindow.Create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32), WINDOW_TITLE);
    myWindow.SetFramerateLimit(60); // 60 FPS

    // Chargement de la texture du sol
    myGroundTexture = new sf::Image();
    myGroundTexture->LoadFromFile("../data/textures/ground.png");
    myGroundTexture->SetSmooth(false); // Evite une bordure bizarre sur les textures

    myWindow.SetView( myCamera );
}


////////////////////////////////////////////////////////////
/// Default destructor
////////////////////////////////////////////////////////////
GraphicEngine::~GraphicEngine()
{
    myWindow.Close();
}


////////////////////////////////////////////////////////////
///
///    Heart of the graphic engine.
///    Do action for all drawable elements.
///
////////////////////////////////////////////////////////////
void GraphicEngine::Frame()
{
    // Clean screen
    myWindow.Clear( sf::Color(0, 0, 0 ) );

    // Affichage du sol
    sf::Sprite groundSprite;
    groundSprite.SetImage( *myGroundTexture );
    myWindow.Draw(groundSprite);

    // Draw entities
    for(std::vector<Drawable*>::iterator i = myDrawables.begin(); i < myDrawables.end(); i++)
    {
        if( (*i)->IsVisible() )
            (*i)->Draw( myWindow, myWindow.GetFrameTime() );
    }

    // Affichage de la GUI (Menus)
    myGui.Frame( myWindow );

    // Show the window
    myWindow.Display();
}
////////////////////////////////////////////////////////////
///
///    Add an object in the drawable list.
///
////////////////////////////////////////////////////////////
void GraphicEngine::AddDrawable( Drawable *drawable )
{
    myDrawables.push_back( drawable );
}


////////////////////////////////////////////////////////////
///
///    Add an object in the drawable list.
///
////////////////////////////////////////////////////////////
void GraphicEngine::Clear()
{
    for(std::vector<Drawable*>::iterator i = myDrawables.begin(); i < myDrawables.end(); i++)
        (*i) = NULL;

    // Security
    if(!myDrawables.empty())
        myDrawables.clear();
}


////////////////////////////////////////////////////////////
///
///    Get the window
///
////////////////////////////////////////////////////////////
sf::RenderWindow* GraphicEngine::GetWindow()
{
    return &myWindow;
}


////////////////////////////////////////////////////////////
///
///    Get the camera
///
////////////////////////////////////////////////////////////
sf::View& GraphicEngine::GetCamera() const
{
    return myCamera;
}


////////////////////////////////////////////////////////////
///
///    Get the GUI
///
////////////////////////////////////////////////////////////
Gui* GraphicEngine::GetGui()
{
    return &myGui;
}


void GraphicEngine::OpenPopupLoad()
{
 	PopupLoad popup;
 	behavior->setMode(popup.Display());
 	std::cout << "Carrefour choisi : " << popup.getSelectedCrossroad() << std::endl;
 	std::cout << "Simulation choisie : " << popup.getSelectedSimulation() << std::endl;
}

void GraphicEngine::OpenPopupConfig()
{
 	PopupConfig popup;
 	popup.Display();
}
