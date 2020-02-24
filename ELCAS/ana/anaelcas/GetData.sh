#!/bin/bash

echo *********Get $1**************
scp tof@192.168.11.15:~/ts-elph_2019/elcas_data/$1.dat data/
