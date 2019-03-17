#!/bin/bash
set -e

g++ -std=c++11 -o a.out 2.cpp
g++ -std=c++11 -o b.out bob.cpp

./a.out < 2_input_1.txt > 2_output_me.txt
./b.out < 2_input_1.txt > 2_output_bob.txt

diff 2_output_me.txt 2_output_bob.txt

if [ $? -ne 0 ];
then
    vimdiff 2_output_me.txt 2_output_bob.txt
fi
