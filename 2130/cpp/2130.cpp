#include <iostream>

#ifndef ONLINE_JUDGE
#include <sstream>
void test(int n = 1)
{
    std::stringstream ss;
    ss << "t" << n;
    freopen(ss.str().c_str(), "rt", stdin);
    freopen("out", "wt", stdout);
}
#endif

uint64_t gcd(uint64_t a, uint64_t b)
{
    a = a%b;
    return a ? gcd(b, a) : b;
}

int main()
{
#ifndef ONLINE_JUDGE
    test(2);
#endif
    uint32_t n, i = 0, larr = 0;
    std::cin >> n;
    uint32_t arr[100001];
    uint64_t a = 1, b, c, MAXA=1000000000000;
    bool q;
    while (i < n)
    {
        std::cin >> b >> q;
        if (q)
        {
            c = (a > b) ? gcd(a, b): gcd(b, a);
            if (c != b)
            {
                a *= b / c;
                if (a > MAXA) break;
                uint32_t j = 0;
                while (j < larr)
                {
                    if  (!(a % arr[j])) break;
                    ++j;
                }
                if (j != larr) break;
                std::cout<<a<<'\n';
            }
            else
            {
                std::cout<<a<<'\n';
            }
        }
        else
        {
            if (a%b)
            {
                arr[larr] = b;
                ++larr;
                std::cout<<a<<'\n';
            }
            else break;

        }
        ++i;
    }
    while (i < n)
    {
        std::cout<<"-1\n";
        ++i;
    }
    return 0;
}