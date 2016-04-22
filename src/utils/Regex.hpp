//
// Regex.hpp for plazza in /home/proqui_g/rendu/cpp_plazza/src/utils
// 
// Made by Guillaume PROQUIN
// Login   <proqui_g@epitech.net>
// 
// Started on  Thu Apr 21 11:52:08 2016 Guillaume PROQUIN
// Last update Fri Apr 22 13:17:50 2016 Guillaume PROQUIN
//

#ifndef		__REGEX_HPP__
# define	__REGEX_HPP__

# include	<iostream>
# include	<vector>
# include	<regex.h>
# include	"Exception.hpp"

class		Regex
{
public:
  static regex_t			compile(const std::string& regex);
  static bool				match(regex_t regex, const std::string& str);
  static std::vector<std::string>	extract(regex_t regex, const std::string& str);
};

#endif
