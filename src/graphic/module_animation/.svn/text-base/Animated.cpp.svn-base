////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "Animated.hpp"

////////////////////////////////////////////////////////////
/// Default constructor
////////////////////////////////////////////////////////////
Animated::Animated() : myCurrentAnimation("Wait"), myCurrentFrame(0), mySprite(NULL), myTimeBetween(0.1f), myElapsedTime(0.0f), myReverse(true), meReverseState(true)
{

}

////////////////////////////////////////////////////////////
/// Default destructor
////////////////////////////////////////////////////////////
Animated::~Animated()
{
    mySprite = NULL;
}


////////////////////////////////////////////////////////////
/// Play current animation
////////////////////////////////////////////////////////////
void Animated::Play( float time )
{
    // on retranche le temps écoulé a notre compteur
    myElapsedTime -= time;

    // Si Le temps entre chaque frame est atteint
    if (myElapsedTime <= 0.f && myAnimations[ myCurrentAnimation ].Size() > 1 )
    {
        // On réinitialise notre compteur
        myElapsedTime = myTimeBetween;

        // Animation in reverse
        if( myReverse)
        {
            if ( meReverseState )
            {
                myCurrentFrame++;

                if (myCurrentFrame >= myAnimations[ myCurrentAnimation ].Size() - 1 )
                    meReverseState = false;
            }
            else
            {
                myCurrentFrame--;

                if (myCurrentFrame <= 0 )
                    meReverseState = true;
            }
        }

        SetFrame( myCurrentFrame );
    }
}


////////////////////////////////////////////////////////////
/// Add an animation
////////////////////////////////////////////////////////////
void Animated::AddAnimation( std::string name, Animation &animation )
{
    myAnimations.insert( std::pair<std::string, Animation>( name, animation ) );
}


////////////////////////////////////////////////////////////
/// Set animation
////////////////////////////////////////////////////////////
void Animated::SetAnimation( std::string name )
{
    myCurrentAnimation = name;
}


////////////////////////////////////////////////////////////
/// Change image of player
////////////////////////////////////////////////////////////
void Animated::SetSprite( sf::Sprite* sprite )
{
    if( sprite != NULL )
        mySprite = sprite;
}


////////////////////////////////////////////////////////////
/// Change subrect of image
////////////////////////////////////////////////////////////
void Animated::SetFrame( unsigned int frame )
{
    if ( mySprite != NULL )
    {
        sf::Rect<int> position = myAnimations[ myCurrentAnimation ].GetFrame( frame ).position;

        mySprite->SetSubRect( position );
    }
}

////////////////////////////////////////////////////////////
/// Change direction of player
////////////////////////////////////////////////////////////
void Animated::SetDirection( bool direction )
{
    mySprite->FlipX( direction);
}


////////////////////////////////////////////////////////////
/// Get the number of animation
////////////////////////////////////////////////////////////
unsigned int Animated::Size() const
{
    return myAnimations.size();
}


////////////////////////////////////////////////////////////
/// Delete an animation
////////////////////////////////////////////////////////////
void Animated::DeleteAnimation( std::string &name )
{
    std::map<std::string, Animation>::iterator current;

    for( current = myAnimations.begin(); current != myAnimations.end(); current++)
    {
        if( current->first == name )
        {
            myAnimations.erase(current);
            break;
        }
    }
}
