#include <cstdio>
#include <cstdint>

int16_t *POINTS[2];

struct List
{
    int16_t value;
    List *next = nullptr;
    List *last = nullptr;
};

int32_t qd(int16_t &a, int16_t &b)
{
    int16_t x0 = POINTS[0][a];
    int16_t x1 = POINTS[0][b];
    int16_t y0 = POINTS[1][a];
    int16_t y1 = POINTS[1][b];
    return (x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1);
}

int main()
{
    int16_t N;
    scanf("%hd", &N);
    N += 2;
    POINTS[0] = new int16_t[N];
    POINTS[1] = new int16_t[N];
    for(int16_t i = 0; i < N; ++i) scanf("%hd %hd", &POINTS[0][i], &POINTS[1][i]);
    List *order = new List;
    List *end = new List;
    order->value = 0;
    end->value = 1;
    order->next = end;
    end->last = order;
    for(int16_t i = 2; i < N; ++i)
    {
        List *t0 = end->last;
        List *t1 = end;
        List *t2 = new List;
        t2->value = i;
        while(t0 && (qd(t0->value, t2->value) >= qd(t0->value, t1->value) + qd(t1->value, t2->value)))
        {
            t1 = t0;
            t0 = t0->last;
        }
        if(t1->next)
        {
            t1->next->last = t2;
            t2->next = t1->next;
        }
        else
        {
            end = t2;
        }
        t1->next = t2;
        t2->last = t1;
    }
    char ret[11000];
    int16_t reti = sprintf(ret, "YES\n");
    while(order->next)
    {
        reti += sprintf(&ret[reti], "%hd ", order->value + 1);
        order = order->next;
        delete order->last;
    }
    sprintf(&ret[reti], "%hd\n", order->value + 1);
    delete order;
    printf("%s", ret);
    delete [] POINTS[0];
    delete [] POINTS[1];
    return 0;
}

/*
3
3 5
1 3
4 1
5 4
22 4
*/