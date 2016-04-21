//
// Parser.cpp for plazza in /home/proqui_g/rendu/cpp_plazza/src/utils
// 
// Made by Guillaume PROQUIN
// Login   <proqui_g@epitech.net>
// 
// Started on  Fri Apr 15 13:16:22 2016 Guillaume PROQUIN
// Last update Thu Apr 21 13:14:38 2016 Guillaume PROQUIN
//

#include "Parser.hpp"

Parser::Parser(const std::string& regex, const std::string& filename)
{
  this->_file.open(filename);
  if (!this->_file)
    throw (exception("Can't open file: " + filename));
  this->_regex = Regex::compile(regex);
}

Parser::~Parser()
{
  this->_file.close();
  regfree(&this->_regex);
}

std::ifstream&			Parser::getFile()
{
  return (this->_file);
}

regex_t				Parser::getRegex()
{
  return (this->_regex);
}

std::vector<std::string>	Parser::parseLine(std::string& line)
{
  return (Regex::extract(this->_regex, line));
}

std::vector<std::string>	Parser::parse()
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
