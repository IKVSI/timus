#include <cstdio>
#include <cstdint>

struct Step
{
    int32_t x;
    int32_t y;
    char c;
    int32_t parent;
    int32_t length;
};

int32_t testquater(int32_t &x, int32_t &y)
{
    if ((x >= 0) && (y >= 0)) return 0;
    else if ((x < 0) && (y >= 0)) return 1;
    else if (x < 0) return 2;
    else return 3;
}

int32_t length(int32_t &x, int32_t &y)
{
    return x * x + y * y;
}

int main()
{
    int16_t N, L;
    scanf("%hd\n%hd", &N, &L);
    Step * steps = new Step[8*N+2];
    steps[1].x = 0;
    steps[1].y = 0;
    steps[1].c = ' ';
    steps[1].parent = 0;
    steps[1].length = 0;
    int32_t stepsi = 2;
    int32_t * xyr = new int32_t[4];
    xyr[0] = 1;
    xyr[3] = xyr[2] = xyr[1] = 0;
    int32_t * ryx;
    for(int32_t i = 0; i < N; ++i)
    {
        int16_t x, y;
        scanf("%hd %hd", &x, &y);
        ryx = new int32_t[4];
        ryx[0] = ryx[1] = ryx[2] = ryx[3] = 0;
        for(int j = 0; j < 4; ++j) if (xyr[j])
        {
            int32_t tx = steps[xyr[j]].x + x;
            int32_t ty = steps[xyr[j]].y + y;
            int16_t tq = testquater(tx, ty);
            int32_t tlength = length(tx, ty);
            if ((!ryx[tq]) || (steps[ryx[tq]].length > tlength))
            {
                steps[stepsi].x = tx;
                steps[stepsi].y = ty;
                steps[stepsi].c = '+';
                steps[stepsi].parent = xyr[j];
                steps[stepsi].length = tlength;
                ryx[tq] = stepsi;
                ++stepsi;
            }
            tx = steps[xyr[j]].x - x;
            ty = steps[xyr[j]].y - y;
            tq = testquater(tx, ty);
            tlength = length(tx, ty);
            if ((!ryx[tq]) || (steps[ryx[tq]].length > tlength))
            {
                steps[stepsi].x = tx;
                steps[stepsi].y = ty;
                steps[stepsi].c = '-';
                steps[stepsi].parent = xyr[j];
                steps[stepsi].length = tlength;
                ryx[tq] = stepsi;
                ++stepsi;
            }
        }
        /*
        for(int k = 0; k < 4; ++k) if (xyr[k])
        {
            printf("xyr[%hd]:%hd: length(%hd, %hd) = %hd; %c\n", k, xyr[k], steps[xyr[k]].x, steps[xyr[k]].y, steps[xyr[k]].length, steps[xyr[k]].c );
        }
        */
        delete [] xyr;
        xyr = ryx;
    }
    /*
    for(int k = 0; k < 4; ++k) if (xyr[k])
    {
        printf("xyr[%hd]:%hd: length(%hd, %hd) = %hd; p=%d %c\n", k, xyr[k], steps[xyr[k]].x, steps[xyr[k]].y, steps[xyr[k]].length, steps[xyr[k]].parent, steps[xyr[k]].c );
    }
    */
    char * ret = new char[N+1];
    int32_t p = stepsi - 1;
    for(int i = 0; i < 4; ++i) if((xyr[i]) && (steps[xyr[i]].length < steps[p].length)) p = xyr[i];
    delete []xyr;
    ret[N] = '\0';
    while(p != 1)
    {
        --N;
        ret[N] = steps[p].c;
        p = steps[p].parent;
    }
    printf("YES\n%s", ret);
    delete [] ret;
    delete [] steps;
    return 0;
}