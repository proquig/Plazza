//
// Created by pogam-_g on 4/18/16.
//

#include "AOrder.hpp"

const std::string &Plazza::AOrder::getFile() const
{
  return this->_file;
}

void Plazza::AOrder::setFile(const std::string &file)
{
  this->_file = file;
}

std::ostream &operator<<(std::ostream &out, const Plazza::AOrder &order)
{
  out << order.getOrder() << " " << order.getFile();
  return (out);
}
