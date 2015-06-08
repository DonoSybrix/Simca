////////////////////////////////////////////////////////////
//
// Simca
// Copyright (C) 2011 Orhan Donovan ( dono.orhan@gmail.com )
//
// - Author : Orhan Donovan.
// - Create : 04/02/2011.
// - Desc.  : Animation ( Ex : Walk, Run, ... )
//
////////////////////////////////////////////////////////////

#ifndef H_ANIMATION
#define H_ANIMATION

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "../../utils/library.hpp"
#include "Frame.hpp"

class Animation
{
    public:

        // Constructor / Destructor.
        Animation();
        ~Animation();

        // Add a frame
        void   AddFrame( Frame &frame );

        // Get a frame
        Frame& GetFrame( unsigned int number );

        // Get number of frame
        unsigned int Size() const;

    private:

        // Frames
        std::vector<Frame> myFrames;

};

#endif // H_ANIMATION

