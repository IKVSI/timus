#include <iostream>
#include <sstream> 

void printtree(int l, unsigned long &n, int t, unsigned long * &tree)
{
    for(int i = 0; i < t; ++i) std::cout << "\t";
    std::cout << l << ": " << tree[l] << "\n";
    l <<= 1;
    if (l < n)
    {
        printtree(l, n, t + 1, tree);
        printtree(l + 1, n, t + 1, tree);
    }
}

void updatetree(unsigned long cursor, unsigned long &n, unsigned long * &tree)
{
    while (cursor != 1)
    {
        cursor >>= 1;
        --tree[cursor];
    }
}

void downtree(unsigned long &cursor, unsigned long &n, unsigned long * &tree)
{
    if ((cursor << 1) >= n) return;
    cursor <<= 1;
    if (tree[cursor]) downtree(cursor, n, tree);
    else
    {
        ++cursor;
        downtree(cursor, n, tree);
    }
}

void walktree(unsigned long &cursor, unsigned long &shag, unsigned long n, unsigned long * &tree)
{
    while (shag)
    {
        if ((cursor == 1) || (!(cursor&1) && (tree[cursor + 1] >= shag)))
        {
            if (cursor != 1) ++cursor;
            downtree(cursor, n, tree);
            --shag;
        }
        else
        {
            if (!(cursor&1)) shag -= tree[cursor + 1];
            cursor >>= 1;
        }
    }
}

int main()
{
    unsigned long N, K;
    std::cin >> N >> K;
    unsigned long n = 1;
    char k = 0;
    while(n < N)
    {
        ++k;
        n <<= 1;
    }
    n <<= 1;
    unsigned long * tree = new unsigned long [n];
    for (unsigned long i = n >> 1, Ni = 0; i < n; ++Ni, ++i) tree[i] = (Ni < N) ? 1 : 0;
    for (unsigned long i = (n >> 1) - 1; i != 0; --i) tree[i] = tree[i << 1] + tree[(i << 1) + 1];
    unsigned long cursor = n >> 1;
    while (tree[1])
    {
        unsigned long shag = K;
        shag %= tree[1];
        shag = (shag) ? shag - 1 : tree[1] - 1;
        walktree(cursor, shag, n, tree);
        std::cout << cursor - (n >> 1) + 1 << ' ';
        tree[cursor] = 0;
        updatetree(cursor, n, tree);
        shag = 1;
        walktree(cursor, shag, n, tree);
    }
    delete [] tree;
}