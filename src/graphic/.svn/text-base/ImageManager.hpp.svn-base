////////////////////////////////////////////////////////////
//
// Simca
// Copyright (C) 2011 Orhan Donovan ( sybrix44@gmail.com )
//
// - Author : Orhan Donovan.
// - Create : 04/02/2011.
// - Desc.  : Image manager
//
////////////////////////////////////////////////////////////


#ifndef H_IMAGEMANAGER
#define H_IMAGEMANAGER

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include "../utils/Singleton.hpp"
#include "../utils/library.hpp"

class ImageManager : public Singleton<ImageManager>
{
    public:

        friend class Singleton<ImageManager>;

        // Get an image
        sf::Image* GetImage( const std::string &imageName );

        // Delete an image
        void Delete( std::string &imageName );

    private:
        // Constructor / Destructor.
        ImageManager();
        ~ImageManager();

        // All pictures of the game.
        std::map<std::string, sf::Image*> myImages;

        // Create an image
        sf::Image* Create( const std::string &imageName );

        // Search an image
        bool Search( const std::string &imageName, sf::Image* &image );
};

#endif // H_IMAGEMANAGER


