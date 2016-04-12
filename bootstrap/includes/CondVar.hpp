//
// Created by cloquet on 12/04/16.
//

#ifndef CPP_PLAZZA_CONDVAR_HPP
#define CPP_PLAZZA_CONDVAR_HPP

#include "IConVar.hpp"

class ConVar : public IConVar
{
 public:
   void wait(void);
   void signal(void);
   void broadcast(void);
};

void ConVar::wait()
{

}

void ConVar::broadcast()
{

}

void ConVar::signal()
{

}
#endif //CPP_PLAZZA_CONDVAR_HPP
