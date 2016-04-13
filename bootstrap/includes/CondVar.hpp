//
// Created by cloquet on 12/04/16.
//

#ifndef CPP_PLAZZA_CONDVAR_HPP
#define CPP_PLAZZA_CONDVAR_HPP

#include "IConVar.hpp"

class ConVar : public IConVar
{
  pthread_mutex_t _mutex;
  pthread_cond_t _cond;

 public:
  	ConVar();
  	~ConVar(){}
   	void wait(void);
   	void signal(void);
   	void broadcast(void);
};

ConVar::ConVar()
{
  _mutex = PTHREAD_MUTEX_INITIALIZER;
  _cond = PTHREAD_COND_INITIALIZER;
}

void ConVar::wait()
{
  pthread_cond_wait(&_cond, &_mutex);
}

void ConVar::broadcast()
{
  pthread_cond_broadcast(&_cond);
}

void ConVar::signal()
{
  pthread_cond_signal(&_cond);
}

#endif //CPP_PLAZZA_CONDVAR_HPP
