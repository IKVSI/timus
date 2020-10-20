#include <cstdio>
int main()
{
    unsigned int N;
    scanf("%u", &N);
    unsigned short *arr = new unsigned short [N];
    unsigned long long weight = 0;
    unsigned short mn = 65535, mx = 0, size;
    for(unsigned int i = 0; i < N; ++i)
    {
        scanf("%hu", &arr[i]);
        weight += arr[i];
        if (mn > arr[i]) mn = arr[i];
        if (mx < arr[i]) mx = arr[i];
    }
    size = mx - mn + 1;
    unsigned int * mp = new unsigned int[size];
    for(unsigned short i = 0; i < size; ++i) mp[i] = 0;
    for(unsigned int i = 0; i < N; ++i) ++mp[arr[i] - mn];
    unsigned long long nalog = 0;
    for(unsigned int i = 0; i < size; ++i)
    {
        if (mp[i])
        {
            unsigned long long k = (mn + i);
            unsigned long long n = mp[i];
            nalog += weight * k * n * 2 - k * k * n * (n - 1) - n * k * k;
            weight -= n * k;
        }
    }
    printf("%llu", nalog);
    delete [] arr;
    delete [] mp;
    return 0;
}