#include <cstdio>
#include <cstdlib>

int itoa(char * c, int a)
{
    int i=0;
    do
    {
        c[i] = a%10+'0';
        a /= 10;
        ++i;
    }while(a);
    for(int j=0, k=i-1; j<k; ++j, --k)
    {
        char ch = c[k];
        c[k] = c[j];
        c[j] = ch;
    }
    c[i] = '\n';
    return i+1;
}

int funccmp( const void * val1, const void * val2 )
{
    return ( *(int*)val2 - *(int*)val1 ); 
}

int main()
{
    int n, q, k=0;
    scanf("%i", &n);
    int *t = new int[n];
    for(int i=0; i<n; ++i) scanf("%i", &t[i]);
    qsort(t, n, sizeof(int), funccmp);
    for (int i=1; i<n; ++i)
    {
        if(t[i] == t[k]) continue;
        ++k;
        t[k]=t[i];
    }
    ++k;
    scanf("%i", &q);
    char * str = new char[ q * 11 + 1];
    char * istr = str;
    for(int i=0; i<q; ++i)
    {
        int a, mx=0;
        scanf("%i", &a);
        if (a <= t[0])
        {
            istr += itoa(istr, a);
            continue;
        }
        for(int j=0; j<k; ++j)
        {
            if (mx >= t[j]) break;
            int temp1 = a/t[j], temp2 = a%t[j], r;
            if (temp1%2 == 0) r = temp2;
            else r = t[j] - temp2;
            if (r > mx) mx = r;
        }
        istr += itoa(istr, mx);
    }
    istr[0]=0;
    printf("%s", str);
    return 0;
}