//
// Decrypt.hpp for plazza in /home/proqui_g/rendu/cpp_plazza/src/utils
//
// Made by Guillaume PROQUIN
// Login   <proqui_g@epitech.net>
//
// Started on  Mon Apr 18 18:52:23 2016 Guillaume PROQUIN
// Last update Fri Apr 22 17:11:09 2016 Guillaume PROQUIN
//

#ifndef                __DECRYPT_HPP__
# define        __DECRYPT_HPP__

# include	<iostream>
# include	<fstream>
# include	<vector>
# include	"Parser.hpp"
# include	"Regex.hpp"

# define        IS_PRINTABLE(C) (C >= 32 && C <= 126)

namespace Plazza
{
  class Decrypt : public Parser
  {
   private:
    std::ifstream _file;
    regex_t _regex;

   public:
    Decrypt(const IOrder &order);

    virtual ~Decrypt();

    std::vector<std::string> decrypt();

   private:
    std::vector<std::string> decryptXor(const std::string &line);

    std::vector<std::string> decryptCaesar(const std::string &line);
  };
}

#endif
