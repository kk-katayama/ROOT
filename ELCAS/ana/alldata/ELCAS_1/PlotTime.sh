#!/bin/bash

echo *****************Open $1******************
root -l -q Analysis.cpp\(\"$1\"\)
if [ "$#" -eq 2 ]
then root -l PlotTime.cpp\(\"$1.root\",$2\)
elif [ "$#" -eq 1 ]
then root -l PlotTime.cpp\(\"$1.root\"\)
fi
#rm -rf $1.root
