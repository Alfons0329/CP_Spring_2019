from sys import stdin
import re
import collections as col
stk = col.deque()
for each_line in stdin:
    res = 0
    splitted = re.split(r'(\*|\+)', each_line)
    stk.clear()
    for i in splitted:
        stk.append(i)
        if len(stk) == 3:
            if stk[1] == '+':
                res = int(stk[0]) + int(stk[2])
            else:
                res = int(stk[0]) * int(stk[2])
            stk.clear()
            stk.append(res)

    print(stk[0])

