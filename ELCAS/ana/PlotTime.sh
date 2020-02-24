#!/bin/bash

echo *****************Open $1******************
root -l -q Analysis.cpp\(\"$1\"\)
root -l PlotTime.cpp\(\"$1.root\"\)

