#include <cstdio>
#include <cstdint>

void sort(int32_t *& source, int32_t &size)
{
    int32_t *target = new int32_t[size];
    int32_t window = 1;
    while(window < size)
    {
        int32_t i = 0, k = 0;
        while(i < size)
        {
            int32_t j = i + window, si = j, sj = j + window;
            if (si > size) si = size;
            if (sj > size) sj = size;
            while(k < sj)
            {
                if (j >= sj) target[k++] = source[i++];
                else if (i >= si) target[k++] = source[j++];
                else if (source[i] < source[j]) target[k++] = source[i++];
                else target[k++] = source[j++];
            }
            i = sj;  
        }
        int32_t * temp = target;
        target = source;
        source = temp;
        window <<= 1;
    }
    delete [] target;
}

int32_t unify(int32_t *& source, int32_t &size)
{
    int32_t newsize = size;
    for(int32_t i = 1; i < size; ++i) if (source[i] == source[i-1]) --newsize;
    int32_t * target = new int32_t[newsize];
    target[0] = source[0];
    for(int32_t i = 1, j = 1; j < newsize; ++i) if (target[j - 1] != source[i]) target[j++] = source[i];
    int32_t tempsize = 1;
    while (tempsize < newsize) tempsize <<= 1;
    tempsize = (tempsize << 1) - 1;
    delete [] source;
    source = target;
    size = newsize;
    return tempsize;
}

int32_t gcd(int32_t a, int32_t b)
{
    a %= b;
    return (a) ? gcd(b, a) : b;
}

int32_t getid(int32_t &num, int32_t *& source, int32_t &count)
{
    int32_t start = 0;
    int32_t end = count;
    int32_t middle = (start + end) / 2;
    while(source[middle] != num)
    {
        if(num < source[middle]) end = middle;
        else start = middle;
        middle = (start + end) / 2;
    }
    return middle;
}

int main()
{
    int32_t N;
    scanf("%d", &N);
    int32_t *vvod = new int32_t[N];
    int32_t size = 0;
    for(int32_t i = 0; i < N; ++i)
    {
        char c;
        scanf("\n%c %d", &c, &vvod[i]);
        if (c == '-') vvod[i] = -vvod[i];
        else ++size;
    }

    int32_t *source = new int32_t[size];
    for(int32_t i = 0, j = 0; j < size; ++i) if (vvod[i] > 0) source[j++] = vvod[i];
    sort(source, size);
    int32_t treesize = unify(source, size);

    int32_t *tree = new int32_t[treesize];
    for(int32_t i = 0; i < treesize; ++i) tree[i] = 0;
    int32_t leaves = ((treesize + 1) >> 1) - 1;
    int32_t * inuse = new int32_t[size];
    for(int32_t i = 0; i < size; ++i) inuse[i] = 0;
    for(int32_t i = 0; i < N; ++i)
    {
        int32_t num = vvod[i];
        bool fl = (num < 0);
        if (fl) num = - num;
        int32_t id = getid(num, source, size);
        if (fl) --inuse[id];
        else ++inuse[id];
        if (((fl) && (!inuse[id])) || ((!fl) && (inuse[id] == 1)))
        {
            if (fl) tree[id+leaves] = 0;
            else tree[id+leaves] = source[id];
            id = id + leaves;
            while(id)
            {
                if(!(id&1)) --id;
                int32_t newid = id / 2;
                if (!tree[id]) tree[newid] = tree[id+1];
                else tree[newid] = gcd(tree[id+1], tree[id]);
                id = newid;
            }
        }
        if (tree[0]) printf("%d\n", tree[0]);
        else printf("1\n");
    }
    delete [] source;
    delete [] vvod;
    delete [] tree;
    delete [] inuse;
    return 0;
}