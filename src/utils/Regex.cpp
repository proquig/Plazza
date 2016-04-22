//
// Regex.cpp for plazza in /home/proqui_g/rendu/cpp_plazza/src/utils
// 
// Made by Guillaume PROQUIN
// Login   <proqui_g@epitech.net>
// 
// Started on  Thu Apr 21 11:51:51 2016 Guillaume PROQUIN
// Last update Fri Apr 22 14:24:44 2016 Guillaume PROQUIN
//

#include "Regex.hpp"

regex_t				Regex::compile(const std::string& regex)
{
  regex_t			reg;

  if (regcomp(&reg, regex.c_str(), REG_EXTENDED))
    throw (exception("Can't compile regex"));
  return reg;
}

bool				Regex::match(regex_t regex, const std::string& str)
{
  regmatch_t			match;
  int				no_match;

  no_match = regexec(&regex, str.c_str(), 1, &match, 0);
  if (no_match && no_match != REG_NOMATCH)
    throw (exception("Regex match failed"));
  return (!no_match);
}

std::vector<std::string>	Regex::extract(regex_t regex, const std::string& str)
{
  std::vector<std::string>	ret;
  std::string			tmp_str = str;
  regmatch_t			match;
  int				no_match;
  int				start_match;
  int				end_match;

  while (!(no_match = regexec(&regex, tmp_str.c_str(), 1, &match, 0)))
    {
      start_match = match.rm_so;
      end_match = match.rm_eo;
      ret.push_back(std::string(tmp_str, start_match, (end_match - start_match)));
      tmp_str.assign(tmp_str, end_match, -1);
    }
  if (no_match != REG_NOMATCH)
    throw (exception("Regex match failed"));
  return ret;
}
