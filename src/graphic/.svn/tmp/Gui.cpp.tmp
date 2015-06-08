////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "Gui.hpp"
#include "PopupLoad.hpp"

////////////////////////////////////////////////////////////
/// Default constructor
////////////////////////////////////////////////////////////
Gui::Gui()
{
    // Chargement du menu du haut
    myMainState    = 0;
    myMainPosition = 0;
    myMainTexture.LoadFromFile("../data/textures/main.png");
    myMainSprite.SetImage( myMainTexture );
    myMainSprite.SetPosition( WINDOW_WIDTH / 2 - (182 / 2), myMainPosition );
}


////////////////////////////////////////////////////////////
/// Default destructor
////////////////////////////////////////////////////////////
Gui::~Gui()
{

}

////////////////////////////////////////////////////////////
///
///    GUI actions
///
////////////////////////////////////////////////////////////
void Gui::Frame( sf::RenderWindow &window )
{
    // Gestion du menu du haut
    if( myMainState == 2 )
        ShowToolBar();
    else if( myMainState == 3 )
        HideToolBar();

    // Affichage du menu du haut
    window.Draw( myMainSprite );
}



////////////////////////////////////////////////////////////
///
///    Toggle the top main
///
////////////////////////////////////////////////////////////
void Gui::ToggleToolBar()
{
    if( myMainState == 1)
        myMainState = 2;
    else
        myMainState = 3;
}



////////////////////////////////////////////////////////////
///
///    Show the top main
///
////////////////////////////////////////////////////////////
void Gui::ShowToolBar()
{
    myMainPosition += 2;
    if( myMainPosition > 0 )
    {
        myMainPosition = 0;
        myMainState = 1;
    }

    myMainSprite.SetPosition( WINDOW_WIDTH / 2 - (182 / 2), myMainPosition );
}


////////////////////////////////////////////////////////////
///
///    Hide the top main
///
////////////////////////////////////////////////////////////
void Gui::HideToolBar()
{
    myMainPosition -= 2;
    if( myMainPosition < -28 )
    {
        myMainPosition = -28;
        myMainState = 0;
    }

    myMainSprite.SetPosition( WINDOW_WIDTH / 2 - (182 / 2), myMainPosition );
}

////////////////////////////////////////////////////////////
///
///   Menu pour charger Carrefours et Simulations
///
////////////////////////////////////////////////////////////
//void Gui::ShowPopupLoad()
//{
//	PopupLoad popup();
//	popup.Display();
//}
