#!/usr/bin/python3
'''
def f(pre, V, i):
    for j in V[i][3]:
        if i == 0:
            print(j)
            f(j, V, V[i][3][j][0])
        else:
            print(j+pre+j)
            f(j+pre+j, V, V[i][3][j][0])
'''

# (id, length, back, dictnext)
V = [(0, -1, 0, {}), (1, 0, 0, {})]
R = []
last = V[0]
S = input()
for i in range(len(S)):
    while ( i - last[1] - 1 < 0) or (S[i] != S[i-last[1]-1]):
        last = V[last[2]]
    if S[i] not in last[3]:
        if last[0]:
            templast = V[last[2]]
            while S[i] != S[i-templast[1]-1]:
                templast = V[templast[2]]
            back = templast[3][S[i]][0]
        else:
            back = 1
        V.append((len(V), last[1]+2, back, {}))
        last[3][S[i]] = V[-1]
    last = last[3][S[i]]
    R.append(str(len(V)-2))

print(' '.join(R))

'''
eertree
'''
    