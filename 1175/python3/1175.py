def f(x, y, a1, a2, a3, a4, b1, b2, c):
    H = a1*x*y+a2*x+a3*y+a4
    if H > b1:
        while H > b2: H -= c
    return H

A1, A2, A3, A4, B1, B2, C = [int(i) for i in input().split(" ")]
x1, x2 = [int(i) for i in input().split(" ")]
xs1, xs2 = x1, x2
xf1, xf2 = x1, x2
xs1, xs2 = xs2, f(xs1, xs2, A1, A2, A3, A4, B1, B2, C)
xf1, xf2 = xf2, f(xf1, xf2, A1, A2, A3, A4, B1, B2, C)
xf1, xf2 = xf2, f(xf1, xf2, A1, A2, A3, A4, B1, B2, C)
while (xf1 != xs1) or (xf2 != xs2):
    xs1, xs2 = xs2, f(xs1, xs2, A1, A2, A3, A4, B1, B2, C)
    xf1, xf2 = xf2, f(xf1, xf2, A1, A2, A3, A4, B1, B2, C)
    xf1, xf2 = xf2, f(xf1, xf2, A1, A2, A3, A4, B1, B2, C)
q = 1
xf1, xf2 = xf2, f(xf1, xf2, A1, A2, A3, A4, B1, B2, C)
while (xf1 != xs1) or (xf2 != xs2):
    xf1, xf2 = xf2, f(xf1, xf2, A1, A2, A3, A4, B1, B2, C)
    q += 1
z1, z2 = x1, x2
p = 0
while (xs1 != z1) or (xs2 != z2):
    xs1, xs2 = xs2, f(xs1, xs2, A1, A2, A3, A4, B1, B2, C)
    z1, z2 = z2, f(z1, z2, A1, A2, A3, A4, B1, B2, C)
    p += 1
print(p+1, q)