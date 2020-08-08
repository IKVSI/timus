from sys import stdin, stdout

def gcd(a, b):
    a %= b
    return gcd(b, a) if a else b

n = int(next(stdin))
a = 1
t = []
out = []
MAXA = 1000000000000
while n:
    s = next(stdin)
    b = int(s[:-3])
    if s[-2] == "1":
        c = gcd(b, a)
        if b != c:
            a *= b//c
            if a > MAXA:
                break
            for j in t:
                if not (a%j):
                    break
            else:
                out.append(a)
                n -= 1
                continue
            break
        else:
            out.append(a)
            n -= 1
    else:
        if a%b:
            t.append(b)
            out.append(a)
        else:
            break
        n -= 1
while n:
    out.append(-1)
    n -= 1

stdout.write('\n'.join(map(str, out)))