import re

while True:
    try:
        each_line = input()
    except EOFError:
        break

    splitted = re.split(r'(\*|\+)', each_line)
    res = int(splitted[0])
    for i in range(1, len(splitted), 2):
        if splitted[i] == '*':
            res *= int(splitted[i + 1])
        else:
            res += int(splitted[i + 1])

    print(res)

