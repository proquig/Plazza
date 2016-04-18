//
// Created by pogam-_g on 4/18/16.
//

#ifndef CPP_PLAZZA_ORDERFACTORY_HPP
#define CPP_PLAZZA_ORDERFACTORY_HPP

#include <string>
#include <map>
#include "IOrder.h"

namespace Plazza
{
#define ORDER_TYPE std::string, IOrder (*)()

  class OrderFactory
  {
    std::map<ORDER_TYPE> orderClass;

   public:
    OrderFactory();

    IOrder *createOrder(const std::string &type);
  };
}


#endif //CPP_PLAZZA_ORDERFACTORY_HPP
