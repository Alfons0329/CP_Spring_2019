#/bin/bash
python3 2.py < 2_input.txt > 2_output_py.txt
g++ -std=c++11 2.cpp -o 2.out
./2.out < 2_input.txt > 2_output_cpp.txt

diff_cnt=$(diff 2_output_py.txt 2_output_cpp.txt)
if[ $diff_cnt -ne 0 ];
    vimdiff 2_output_py.txt 2_output_cpp.txt

