from sys import stdin, stdout
from operator import mul, ne

def mulm(matrix1, p):
    matrix2 = [*zip(*matrix1)]
    return [[sum(map(mul, i, j)) % p for j in matrix2] for i in matrix1]

n, m, d, p, q = map(int, next(stdin).split())
v = [*map(str.split, stdin)]
n += 1
curent = [0] * n

window = [curent[:] for i in range(n)]
for i in range(1,n):
    w = window[i]
    w[i] = i*(m-2)
    w[i-1] = i
    window[i-1][i] = (n-i)*(m-1)

curent[0] = 1 % p
if d & 1:
        curent = [sum(map(mul, curent, i)) % p for i in window]
d >>= 1
while d:
    window = mulm(window, p)
    if d & 1:
        curent = [sum(map(mul, curent, i)) % p for i in window]
    d >>= 1
curent = [str(i) for i in curent]
tablo = [[] for i in range(q)]
for i in range(q):
    tablo[i].append(curent[0])
    for j in range(i+1, q):
        t = curent[sum(map(ne, v[i], v[j]))]
        tablo[i].append(t)
        tablo[j].append(t)
stdout.write('\n'.join(' '.join(i) for i in tablo))