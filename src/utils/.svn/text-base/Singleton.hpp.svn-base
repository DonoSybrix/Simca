////////////////////////////////////////////////////////////
//
// Iridium
// Copyright (C) 2011 Orhan Donovan ( sybrix44@gmail.com )
//
// - Author : Orhan Donovan.
// - Create : 04/02/2011.
// - Desc.  : Singleton
//
////////////////////////////////////////////////////////////

#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <cstdlib>

template <typename T>
class Singleton
{
    protected:
        // Constructeur/destructeur
        Singleton()  {}
        ~Singleton() {}

    private:
        // Unique instance
        static T *_singleton;

    public:
        // Interface publique
        static T *getInstance ()
        {
            if(NULL == _singleton)
            {
                _singleton = new T;
            }

            return (static_cast<T*> (_singleton));
        }

        static void kill()
        {
            if(NULL != _singleton)
            {
                delete _singleton;
                _singleton = NULL;
            }
        }


};

template <typename T>
T *Singleton<T>::_singleton = NULL;

#endif // SINGLETON_HPP
