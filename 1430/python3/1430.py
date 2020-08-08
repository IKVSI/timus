def gcd(a, b):
    while (a != 0) and (b != 0):
        if a >= b: a %= b
        else: b %= a
    return a+b

def evklid(a, b):
    if (a > b):
        x = [1, 0, a]
        y = [0, 1, b]
    else:
        x = [0, 1, b]
        y = [1, 0, a]
    #print(x, y)
    if y[2] == 1:
        return y[:2]
    while x[2] != 1:
        d = x[2]//y[2]
        r = x[2]%y[2]
        c = y
        y = [x[0]-y[0]*d, x[1]-y[1]*d,r]
        x = c
    return x[:2]

#print(evklid(13 ,21))

def f2(n, a, b):
    for i in range(b):
        t = n-i
        x = [j*t for j in evklid(a, b)]
        #print(x)
        if x[0] < 0:
            tt = abs(x[0])//b + 1
            x[0] = x[0]%b
            if x[0] == 0: tt -= 1
            x[1] -= a*tt
            if x[1] < 0: continue
        elif x[1] < 0:
            tt = abs(x[1])//a + 1
            x[1] = x[1]%a
            if x[1] == 0: tt -= 1
            x[0] -= b*tt
            if x[0] < 0: continue
        return x


def f(n, a, b):
    t = 0
    m = 0
    tt = a*b*(a+b)
    if tt < n:
        t = (n//tt-1)*a*b
        m = n%tt
        n = m+tt
    res = [t, t]
    r = n
    while n > m:
        k1 = n%a
        k2 = n%b
        if k1 > k2 and r > k2:
            res = [t, t + n//b]
            r = k2
        elif r > k1:
            res = [t + n//a, t]
            r = k1
        n -= a+b
        t += 1
    return res


A, B, N = [int(i) for i in input().split(" ")]
d = gcd(A, B)
A //= d
B //= d
N //= d
rev = False
if A < B:
    rev = True
    A, B = B, A
if B > 50000:
    r = f(N, A, B)
else:
    r = f2(N, A, B)
if rev:
    print(r[1], r[0])
else:
    print(r[0], r[1])