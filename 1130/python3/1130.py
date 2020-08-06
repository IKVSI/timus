#!/usr/bin/python3

def testquarter(x, y):
    if x >= 0 and y >= 0:
        return 0
    elif x >= 0 and y < 0:
        return 3
    elif y >= 0:
        return 1
    else:
        return 2

def length(x, y):
    return x * x + y * y

N = int(input())
L = int(input())

points = [tuple(map(int, input().split())) for i in range(N)]


vectors = [(0, 0, '', -1, 0)]

xyr = [0]

for i in range(len(points)):
    x, y = points[i]
    ryx = [0, 0, 0, 0]
    for j in xyr:
        xj, yj, rj, pj, sj = vectors[j]
        tx, ty = xj + x, yj + y
        tq = testquarter(tx, ty)
        ts = length(tx, ty)
        xq, yq, rq, pq, sq= vectors[ryx[tq]]
        if (not ryx[tq]) or (ts < sq):
            ryx[tq] = len(vectors)
            vectors.append((tx, ty, '+', j, ts))
        tx, ty = xj - x, yj - y
        tq = testquarter(tx, ty)
        ts = length(tx, ty)
        xq, yq, rq, pq, sq= vectors[ryx[tq]]
        if (not ryx[tq]) or (ts < sq):
            ryx[tq] = len(vectors)
            vectors.append((tx, ty, '-', j, ts))
    xyr = [i for i in ryx if i]

temp = {vectors[i][4]:i for i in xyr}
p = temp[min(temp)]
#let = []
ret = []
while(p != -1):
    ret.append(vectors[p][2])
    #let.append(vectors[p])
    p = vectors[p][3]
ret.reverse()
#let.reverse()
#print(let)
print("YES\n{}".format(''.join(ret)))