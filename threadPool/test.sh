
g++ example.cpp Parser.cpp Exception.cpp -pthread -std=c++11 -I. -g ; 
./a.out "0[1-9]([ ]?[0-9]){8}" ../web/emulatari.free.fr/accueil.html
#valgrind ./a.out;
rm -rf a.out;

