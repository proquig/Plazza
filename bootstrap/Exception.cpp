//
// Exception.cpp for  in /home/cloquet/Documents/cpp/cpp_plazza
// 
// Made by Cloquet
// Login   <cloquet@epitech.net>
// 
// Started on  Mon Apr 11 15:01:19 2016 Cloquet
// Last update Mon Apr 11 15:01:22 2016 Cloquet
//

# include "includes/Exception.hpp"

exception::exception(const std::string & msg)
{
  this->_msg = msg;
}

exception::~exception() throw()
{

}

const char *    exception::what() const throw()
{
  return (this->_msg.c_str());
}
