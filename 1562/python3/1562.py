from math import pi

def f(a, b, x0, x1):
    p1 = pi*b*b*x1*(1-x1*x1/(3*a*a))
    p2 = pi*b*b*x0*(1-x0*x0/(3*a*a))
    return (p1-p2)

b, a, n = [float(i) for i in input().split(" ")]
a = a/2
b = b/2
n = int(n)
step = 2*a/n
i = -a
for _ in range(n):
    print("{:.6f}".format(round(f(a, b, i, i+step), 6)))
    i += step