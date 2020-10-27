#include <stdio.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    k-=2;
    for(int i=0; i<n; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        k-=2-(x-y);
    }
    if (k>=0) printf("%i", k);
    else printf("Big Bang!");
    return 0;
}
