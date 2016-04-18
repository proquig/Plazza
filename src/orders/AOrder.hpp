//
// Created by pogam-_g on 4/18/16.
//

#ifndef CPP_PLAZZA_AORDER_HPP
#define CPP_PLAZZA_AORDER_HPP

#include "IOrder.hpp"

namespace Plazza
{
  class AOrder : public IOrder
  {
    std::string _file;

   public:
    virtual const std::string & getFile() const;

    virtual void setFile(const std::string &file);
  };
}

#endif //CPP_PLAZZA_AORDER_HPP
