//
// Parser.cpp for plazza in /home/proqui_g/rendu/cpp_plazza/src/utils
//
// Made by Guillaume PROQUIN
// Login   <proqui_g@epitech.net>
//
// Started on  Fri Apr 15 13:16:22 2016 Guillaume PROQUIN
// Last update Fri Apr 22 18:10:12 2016 Guillaume PROQUIN
//

#include "Parser.hpp"

Plazza::Parser::Parser(const IOrder &order)
{
  this->_file.open(order.getFile());
  if (!this->_file)
    throw (exception("Can't open file: " + order.getFile()));
  this->_regex = Regex::compile(order.getRegex());
}

Plazza::Parser::~Parser()
{
  this->_file.close();
  regfree(&this->_regex);
}

std::ifstream&			Plazza::Parser::getFile()
{
  return (this->_file);
}

regex_t				Plazza::Parser::getRegex() const
{
  return (this->_regex);
}

std::vector<std::string>	Plazza::Parser::parseLine(std::string& line)
{
  return (Regex::extract(this->_regex, line));
}

std::vector<std::string>	Plazza::Parser::parse()
{
  std::vector<std::string>	ret;
  std::vector<std::string>	tmp;
  std::string			line;

  while (std::getline(this->_file, line))
    {
      tmp = this->parseLine(line);
      ret.insert(ret.end(), tmp.begin(), tmp.end());
    }
  return (ret);
}
