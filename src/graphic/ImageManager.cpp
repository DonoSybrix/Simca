////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "ImageManager.hpp"

////////////////////////////////////////////////////////////
/// Default constructor
////////////////////////////////////////////////////////////
ImageManager::ImageManager()
{

}

////////////////////////////////////////////////////////////
/// Default destructor
////////////////////////////////////////////////////////////
ImageManager::~ImageManager()
{
    std::map<std::string, sf::Image*>::iterator current;
    for( current = myImages.begin(); current != myImages.end(); current++ )
    {
        delete current->second;
        myImages.erase(current);
    }
}

////////////////////////////////////////////////////////////
/// Create an image
////////////////////////////////////////////////////////////
sf::Image *ImageManager::Create( const std::string &imageName )
{
    sf::Image *image = new sf::Image();

    if( image->LoadFromFile( imageName ) )
    {
        myImages.insert( std::pair<std::string, sf::Image*>(imageName, image) );
        return image;
    }
    else
        delete image;

    return NULL;
}

////////////////////////////////////////////////////////////
/// Get an image
////////////////////////////////////////////////////////////
sf::Image *ImageManager::GetImage( const std::string &imageName )
{
    sf::Image *image = NULL;

    // Image does not exist ? Create it !
    if( !Search(imageName, image) )
        image = Create( imageName );

    return image;
}

////////////////////////////////////////////////////////////
/// Search an image
////////////////////////////////////////////////////////////
bool ImageManager::Search(const std::string &imageName, sf::Image* &image)
{
    std::map<std::string, sf::Image*>::iterator current;

    current = myImages.find( imageName );

    if( current == myImages.end() )
        return false;
    else
        image = current->second;

    return true;
}


////////////////////////////////////////////////////////////
/// Delete an image
////////////////////////////////////////////////////////////
void ImageManager::Delete( std::string &imageName )
{
    std::map<std::string, sf::Image*>::iterator current;

    for( current = myImages.begin(); current != myImages.end(); current++)
    {
        if( current->first == imageName )
        {
            delete current->second;
            myImages.erase(current);
            break;
        }
    }
}
