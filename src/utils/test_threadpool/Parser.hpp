//
// Parser.hpp for plazza in /home/proqui_g/rendu/cpp_plazza/src/utils
// 
// Made by Guillaume PROQUIN
// Login   <proqui_g@epitech.net>
// 
// Started on  Fri Apr 15 13:20:42 2016 Guillaume PROQUIN
// Last update Fri Apr 15 14:10:53 2016 Guillaume PROQUIN
//

#ifndef		__PARSER_HPP__
# define	__PARSER_HPP__

#include	<iostream>
#include	<fstream>
#include	<vector>
#include	<regex.h>
#include	<stdlib.h>
#include	"Exception.hpp"

class		Parser
{
private:
  regex_t	_regex;
  std::ifstream	_file;
public:
  Parser(const std::string& regex, const std::string& filename);
  ~Parser();
  std::vector<std::string>	parse();
};

#endif