#!/bin/sh

echo "Ceci est un test de déchiffrement fonctionnel"
echo "---OUTPUT START---"
g++ -std=c++11 -W -Wall -Werror -I../ main.cpp ../Decrypt.cpp ../Parser.cpp ../Regex.cpp ../Exception.cpp && ./a.out "chiffrement" encrypted
g++ -std=c++11 -W -Wall -Werror -I../ main.cpp ../Decrypt.cpp ../Parser.cpp ../Regex.cpp ../Exception.cpp && ./a.out "chiffrement" xor
echo "---OUTPUT END---"
echo "Test fini"
rm a.out
echo "Binaire détruit"
