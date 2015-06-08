////////////////////////////////////////////////////////////
//
// Simca
// Copyright (C) 2011 Orhan Donovan ( sybrix44@gmail.com )
//
// - Author : Orhan Donovan.
// - Create : 04/02/2011.
// - Desc.  : Drawable, basic object of grahic engine.
//
////////////////////////////////////////////////////////////

#ifndef H_DRAWABLE
#define H_DRAWABLE

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include "../../utils/library.hpp"
#include "../module_animation/Animated.hpp"

class Drawable
{
    public:

        // Constructor / Destructor.
        Drawable();
        ~Drawable();

        // Draw
        virtual void Draw( sf::RenderWindow &myWindow, float elapsedTime );

        // Get the sprite
        sf::Sprite* GetSprite();

        // Change la visibilité du sprite
        void SetVisibility( bool visible );

        // Get myIsDrawable
        bool IsVisible() const;

    protected:

        // Animations
        Animated myAnimations;

        // Sprite
        sf::Sprite mySprite;

        // Draw or not entity
        bool isVisible;

};

#endif // H_DRAWABLE

