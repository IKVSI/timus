def power1(a, b, p):
    res = 1
    while b:
        if b&1:
            res = (a*res)%p
        a = (a*a)%p
        b >>= 1
    return res

def checkprime(n):
    t = n-1
    S = 0
    while not t&1:
        t >>= 1
        S += 1
    for a in (2, 3, 5, 7, 11):
        if n == a:
            return True
        tmp = power1(a, t, n)
        if tmp == 1 or tmp == n-1: continue
        for i in range(1, S):
            tmp = tmp*tmp%n
            if tmp == n-1: break
            if tmp == 1: return False
        else:
            return False
        continue
    return True

N = 0
T = int(input())
if T == 12:
    print(input())
    exit()
if T: N = int(input())*(10**(12-T)) + 1
N = max(3, N)
while not checkprime(N): N += 2
print('{:0>12}'.format(N))