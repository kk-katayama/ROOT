#!/bin/bash

#echo *********Get $1**************
expect -c "
set timeout 5
spawn scp tof@192.168.11.15:~/ts-elph_2019/elcas_data/$1.dat data/
expect \"password:\"
send \"elcas2019\n\"
interact
"
