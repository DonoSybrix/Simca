////////////////////////////////////////////////////////////
//
// Iridium
// Copyright (C) 2011 Orhan Donovan ( dono.orhan@gmail.com )
//
// - Author : Orhan Donovan.
// - Desc.  : Entity.
//
////////////////////////////////////////////////////////////

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>
#include "../graphic/ImageManager.hpp"
#include "../graphic/types/Drawable.hpp"
#include "../physic/type/PhysicBody.hpp"

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
class Entity
{
    public:
		Entity();
		virtual ~Entity();

        // Set width
        void SetWidth( const unsigned int width );

        // Set height
        void SetHeight( const unsigned int height );

        // Set radius
        void SetRadius( float radius );

        // Get width
        unsigned int GetWidth() const;

        // Get height
        unsigned int GetHeight() const;

        // Get radius
        float GetRadius() const;

        // Entity is draggable ?
        bool IsDraggable();

        // Init methode
        virtual void Init();

        // Update methode
        virtual void Update();


    protected:

        // Width and height
        unsigned int myWidth;
        unsigned int myHeight;

        // Angle de l'entite
        float myRadius;

        // Element deplacable ?
        bool isDraggable;

};

#endif // ENTITY_HPP

