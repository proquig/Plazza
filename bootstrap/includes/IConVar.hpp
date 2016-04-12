//
// Created by cloquet on 12/04/16.
//

#ifndef CPP_PLAZZA_ICONVAR_HPP
#define CPP_PLAZZA_ICONVAR_HPP


class IConVar
{
 public:
  virtual void wait(void) = 0;
  virtual void signal(void) = 0;
  virtual void broadcast(void) = 0;
};


#endif //CPP_PLAZZA_ICONVAR_HPP
