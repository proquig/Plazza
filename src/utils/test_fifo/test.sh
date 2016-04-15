#!/bin/sh

echo "Ceci est un test de fifo fonctionelle"
g++ test.cpp ../Fifo.cpp ../Exception.cpp -I../ ; ./a.out
echo "Test finit"
rm a.out
echo "Binaire détruit"
