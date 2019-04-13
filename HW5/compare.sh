#!/bin/bash

g++ -O2 -std=c++11 extra_choco.cpp -o correct.out
g++ -O2 -std=c++11 1.cpp -o wrong.out

for i in 1 2 3 4 5 6
do
    ./correct.out < 1_input_$i.txt > ping.txt
    ./wrong.out < 1_input_$i.txt > me.txt

    diff ping.txt me.txt > /dev/null
    if [ $? -ne 0 ]
    then
        vimdiff ping.txt me.txt
    fi

done
