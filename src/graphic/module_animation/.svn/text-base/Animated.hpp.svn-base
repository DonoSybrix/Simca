////////////////////////////////////////////////////////////
//
// Simca
// Copyright (C) 2011 Orhan Donovan ( dono.orhan@gmail.com )
//
// - Author : Orhan Donovan.
// - Create : 04/02/2011.
// - Desc.  : Content all animations of an entity by exemple.
//
////////////////////////////////////////////////////////////

#ifndef H_ANIMATED
#define H_ANIMATED

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "../../utils/library.hpp"
#include "../../utils/defines.hpp"
#include "Animation.hpp"

class Animated
{
    public:

        // Constructor / Destructor.
        Animated();
        ~Animated();

        // Play
        void Play( float time );

        // Add an animation
        void AddAnimation( std::string name, Animation &animation );

        // Set animation
        void SetAnimation( std::string name );

        // Change image of player
        void SetSprite( sf::Sprite* sprite );

        // Change subrect of image
        void SetFrame( unsigned int frame );

        // Change direction of player
        void SetDirection( bool direction );

        // Get the number of animation
        unsigned int Size() const;

        // Delete an animation
        void DeleteAnimation( std::string &name );

    private:

        // Animations
        std::map<std::string, Animation> myAnimations;

        // Animation to play
        std::string myCurrentAnimation;

        // Current frame of animation
        unsigned int myCurrentFrame;

        // Image source
        sf::Sprite* mySprite;

        // Time between animation
        float myTimeBetween;

        // Time elapsed since last round
        float myElapsedTime;

        // Animation is in style : Begin -> End and End -> Begin
        bool myReverse;

        // If reverse get style
        bool meReverseState;
};

#endif // H_ANIMATED


