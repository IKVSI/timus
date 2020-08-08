#!/usr/bin/python3

def quaddist(a, b):
    return (a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2

N = int(input()) + 2
points = [tuple(map(int, input().split())) for i in range(N)]

order = [0, 1]

for i in range(2, N):
    j = i
    while( (j >= 2) and (quaddist(points[order[j - 2]], points[i]) >= (quaddist(points[order[j - 2]], points[order[j - 1]]) + quaddist(points[order[j-1]], points[i])))):
        j -= 1
    order.insert(j, i)

order = map(lambda x: str(x+1), order)
print("YES\n{}\n".format(' '.join(order)))