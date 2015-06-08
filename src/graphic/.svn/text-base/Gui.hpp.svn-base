////////////////////////////////////////////////////////////
//
// Simcas
// Copyright (C) 2011 Orhan Donovan ( dorhan@epsi.fr )
//
// - Author : Orhan Donovan.
// - Create : 15/04/2011.
// - Desc.  : Gui
//
////////////////////////////////////////////////////////////


#ifndef H_GUI
#define H_GUI

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "../utils/defines.hpp"
#include <SFML/Graphics.hpp>

class Gui
{
    public:

        // Constructor / Destructor.
        Gui();
        ~Gui();

        // Loop of the gui (Animations)
        void Frame( sf::RenderWindow &window );

        // Toggle the top main
        void ToggleToolBar();

        // Show the top mail
        void ShowToolBar();

        // Show the top mail
        void HideToolBar();

        // Project's Menu
        void ShowPopupLoad();

    private:

        // Main
        sf::Image   myMainTexture;
        sf::Sprite  myMainSprite;
        int         myMainState;      // 0 = ferme. 1 - Ouvert 2 - En cours d'ouverture. 3 - En cours de fermeture
        int         myMainPosition;   // Position du menu en Y.

};

#endif

