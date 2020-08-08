#include <stdio.h>
#include <cmath>
#define pi 3.1415926535

int main()
{
	int n, t;
	scanf("%i %i", &n, &t);
	int len = (n>>3)/t;
	double* mem = new double[n];
	double zero=0;
	for (int i=0;i<n;++i)
	{
		double temp;
		scanf("%lf", &temp);
		zero += temp;
		mem[i] = temp;
	}
	zero = zero/n;
	double mxs = 0;
    double mns = 0;
    for (int i=0; i<n; i+=t)
    {
        double mx = zero;
        double mn = zero;
        for(int j=0; j<t;++j)
        {
            if(mem[i+j] > mx) mx = mem[i+j];
            if(mem[i+j] < mn) mn = mem[i+j];
        }
        mxs += mx;
        mns += mn;
    }
    mxs /= len<<3;
    mns /= len<<3;
    //printf("MXS = %lf MNS = %lf\n", (mxs-zero), fabs(mns - zero));
    double lpma = ((mxs-zero) + fabs(mns - zero))/2;
    
    //printf("%lf", lpma);
    double* chk1 = new double[t];
    double* chk0 = new double[t];
    for (int i=0;i<t;++i) chk1[i] = zero + lpma*sin(2*i*pi/t);
    for (int i=0;i<t;++i) chk0[i] = zero + lpma*sin(4*i*pi/t);
	//printf("%lf\n", zero);
	for (int i=0;i<len;++i)
	{
		char p=0;
		for (int j=0;j<8;++j)
		{
			char bit;
			double sum1 = 0;
			double sum0 = 0;
			int tt = 8*t*i+j*t;
			for (int k=1;k<t;++k) sum1 += (mem[tt+k]-zero)*(chk1[k]-zero);
			for (int k=1;k<t;++k) sum0 += (mem[tt+k]-zero)*(chk0[k]-zero);
			//printf("%lf %lf ", sum1, sum0);
			if (sum1 < sum0) bit = 0;
			else bit = 1;
			//printf("%i\n", bit);
			bit <<= j;
			p |= bit;
		}
		printf("%c", p);
	}
	return 0;
}