from sys import stdin
lines = stdin.read().splitlines()
for each_line in lines:
    res = 0
    for i in each_line.split(  ):
        res += int(i)

    print(res)



