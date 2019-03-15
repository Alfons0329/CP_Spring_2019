#!/bin/bash
set -e

g++ -std=c++11 $1.cpp
./a.out < $1_input_1.txt > $1_output_1.txt

diff $1_output_1.txt $1_input_1_ans.txt

if [ $? -eq 0 ];
then
    echo "AC"
else
    echo "WA"
    vimdiff  $1_output_1.txt $1_input_1_ans.txt
fi
