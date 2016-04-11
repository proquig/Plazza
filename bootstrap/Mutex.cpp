//
// Created by cloquet on 11/04/16.
//

#include "Mutex.hpp"

Mutex::Mutex()
{
    mutex = PTHREAD_MUTEX_INITIALIZER;
    std::cout << "Mutex init" << std::endl;
}

Mutex::~Mutex()
{
    pthread_mutex_destroy(&this->mutex);
}

void    Mutex::lock()
{
    pthread_mutex_lock(&this->mutex);
}

void    Mutex::trylock()
{
    pthread_mutex_trylock(&this->mutex);
}

void    Mutex::unlock()
{
    pthread_mutex_unlock(&this->mutex);
}
