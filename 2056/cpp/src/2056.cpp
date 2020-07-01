#include <iostream>

int main()
{
    int16_t N;
    std::cin >> N;
    uint16_t sm = 0, i;
    while (i < N)
    {
        uint16_t q;
        std::cin >> q;
        if (q == 3) break;
        sm += q;
        ++i;
    }
    if (i == N)
    {
        if (sm == 5*N) std::cout << "Named";
        else if (sm*10 >= 45*N) std::cout << "High";
        else std::cout << "Common";
    }
    else
    {
        std::cout << "None";
    }
    return 0;
}
