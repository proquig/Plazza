//
// Parser.cpp for plazza in /home/proqui_g/rendu/cpp_plazza/src/utils
// 
// Made by Guillaume PROQUIN
// Login   <proqui_g@epitech.net>
// 
// Started on  Fri Apr 15 13:16:22 2016 Guillaume PROQUIN
// Last update Tue Apr 19 10:50:41 2016 Guillaume PROQUIN
//

#include "Parser.hpp"

Parser::Parser(const std::string& regex, const std::string& filename)
{
  this->_file.open(filename);
  if (!this->_file)
    throw (exception("Can't open file: " + filename));
  if (regcomp(&this->_regex, regex.c_str(), REG_EXTENDED))
    throw (exception("Can't compile regex"));
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
  std::vector<std::string>	ret;
  regmatch_t			match;
  int				no_match;
  int				start_match;
  int				end_match;

  while (!(no_match = regexec(&this->_regex, line.c_str(), 1, &match, 0)))
    {
      start_match = match.rm_so;
      end_match = match.rm_eo;
      ret.push_back(std::string(line, start_match, (end_match - start_match)));
      line.assign(line, end_match, -1);
    }
  if (no_match != REG_NOMATCH)
    throw (exception("Regex match failed"));
  return ret;
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
