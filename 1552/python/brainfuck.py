#!/usr/bin/python3
from sys import stdin
lenta = [0]*30000
curent = 0
for a in stdin:
    for i in a:
        if i == '.':
            print(chr(lenta[curent]), end='')
        elif i == '>':
            curent = (curent + 1) % 30000
        elif i == '<':
            curent = (curent - 1) % 30000
        elif i == '+':
            lenta[curent] = (lenta[curent] + 1) % 256
        elif i == '-':
            lenta[curent] = (lenta[curent] - 1) % 256
print()