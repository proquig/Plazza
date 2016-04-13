#!/bin/sh

qmake -project;
#echo "Qt+=widgets" >> Qt.pro
qmake
make
