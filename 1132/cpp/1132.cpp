#include <stdio.h>

int power(int a, int b, int p)
{
    if (!b) return 1;
    int z = power(a, b>>1, p);
    if (b&1) return ((a*z)%p*z)%p;
    return (z*z)%p;
}

int leg(int a, int n)
{
    if (a==1) return 1;
    int e=0, s;
    while (!(a&1))
    {
          a >>= 1;
          ++e;
    }
    int r = n&7;
    if ((!(e&1))||(r==1)||(r==7)) s=1;
    else s=-1;
    if (2&n&a) s=-s;
    if (a==1) return s;
    return s*leg(n%a, a);
}

int obr(int a, int b)
{
    int x2=1, x1=0, y2=0, y1=1;
    int q,r,x,y;
    while (b>0)
    {
          q=int(a/b);
          r = a%b;
          x = x2 - q*x2;
          y = y2 - q*y1;
          a = b;
          b = r;
          x2 = x1;
          x1 = x;
          y2 = y1;
          y1 = y;
    }
    return y2;
}

int find(int a, int n)
{
    int t = n-1, S=0;
    while (!(t&1))
    {
        t >>= 1;
        ++S;
    }
    int b=1, d;
    while (leg(b,n)!=-1) ++b;
    int a1 = obr(n, a);
    //printf("a1 = %i\n", a1);
    int c=power(b,t,n);
    int r = power(a,(t+1)>>1,n);
    for (int i=1;i<S;++i)
    {
        d = power(((r*r)%n*a1)%n, 1<<(S-i-1), n);
        if (!((d+1)%n)) r = r*c%n;
        c = c*c%n;
        //printf("r, d, c = %i %i %i\n", r, d, c);
    }
    return r;
}

int main()
{
    int k;
    scanf("%i", &k);
    for(int i=0; i<k; ++i)
    {
        int a,n;
        scanf("%i %i", &a, &n);
        if (n==2) { printf("1\n"); continue; }
        a %= n;
        if (leg(a,n)==-1) {printf("No root\n"); continue;}
        int x = find(a,n);
        if (n-x > x) printf("%i %i\n",x,n-x);
        else printf("%i %i\n",n-x,x);
        //int j=1;
        //while ((j*j-a)%n) ++j;
        //printf("Must be: %i %i\n", j, n-j);
    }
    return 0;
}