//
// Created by cloquet on 11/04/16.
//

#include "ScopedLock.hpp"

ScopedLock::ScopedLock(const Mutex &mutex) : _mutex(mutex)
{
    _mutex.lock();
}

ScopedLock::~ScopedLock()
{
    _mutex.unlock();
}

