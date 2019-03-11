#/bin/bash
set -e
python3 2.py < 2_input.txt > 2_output_py.txt
g++ -std=c++11 2.cpp -o 2.out
./2.out < 2_input.txt > 2_output_cpp.txt

diff 2_output_py.txt 2_output_cpp.txt > /dev/null

if [ $? -ne 0 ]
then
    vimdiff 2_output_py.txt 2_output_cpp.txt
fi
