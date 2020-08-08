def gcd(a, b):
    while (a != 0) and (b != 0):
        if a >= b: a %= b
        else: b %= a
    return a+b

p, q = [int(i) for i in input().split(" ")]
x0, y0 = [int(i) for i in input().split(" ")]
x1, y1 = [int(i) for i in input().split(" ")]
x = x1-x0
y = y1-y0
d = gcd(p, q)
if x%d or y%d:
    print("NO")
    exit()
x //= d
y //= d
if not (x-y)%2:
    print("YES")
    exit()
p //= d
q //= d
if (p-q)%2:
    print("YES")
    exit()
print("NO")