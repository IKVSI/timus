
#include <iostream>
using namespace std;

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

int main()
{
#ifndef ONLINE_JUDGE
    test(3);
#endif
    int16_t n, q;
    int32_t m, d, p;
    cin >> n >> m >> d >> p >> q;
    int32_t v[q][n];
    for(int16_t i = 0; i < q; ++i) for(int16_t j = 0; j < n; ++j) cin >> v[i][j];

    int32_t** window = new int32_t*[n+1];
    for(int16_t i = 0; i <= n; ++i)
    {
    	window[i] = new int32_t[n+1];
    	for(int16_t j = 0; j <= n; ++j) window[i][j] = 0;
    }
    window[0][0] = 0 % p;
    window[1][0] = 1 % p;
    for(int16_t i = 1; i < n; ++i)
    {
    	window[i-1][i] = ((n - i + 1) * (m - 1)) % p;
    	window[i][i] = i * (m - 2) % p;
    	window[i + 1][i] = (i + 1);
    }
    window[n-1][n] = (m - 1) % p;
    window[n][n] = n * (m - 2) % p;

    int32_t* curent = new int32_t[n + 1];
    int32_t* last = new int32_t[n + 1];
    for(int16_t i = 1; i <= n; ++ i)
    {
    	curent[i] = 0;
    }
    curent[0] = 1 % p;

    while (d)
    {
    	if (d & 1)
    	{
    		int32_t* temp = last;
    		last = curent;
    		curent = temp;
    		for(int16_t i = 0; i <= n; ++i )
    		{
    			curent[i] = 0;
    			for(int16_t j = 0; j <= n; ++j)
    			{
    				curent[i] += ((long long)last[j] * window[i][j]) % p;
    				curent[i] %= p;
    			}
    		}
    	}
    	d >>= 1;
    	int32_t** temp = new int32_t*[n+1];
    	for(int16_t i = 0; i <= n; ++i)
    	{
    		temp[i] = new int32_t[n+1];
    		for(int32_t j = 0; j <= n; ++j)
    		{
    			temp[i][j] = 0;
    			for(int32_t k = 0; k <= n; ++k)
    			{
    				temp[i][j] += ((long long)window[i][k] * window[k][j]) % p;
    				temp[i][j] %= p;
    			}
    		}
    	}
    	for(int16_t i = 0; i <= n; ++i) delete [] window[i];
    	delete [] window;
    	window = temp;
    }
    int32_t tablo[q][q];
    for(int16_t i = 0; i < q; ++i)
    {
    	tablo[i][i] = curent[0];
    	for(int16_t j = i+1; j < q; ++j)
    	{
    		int16_t r = 0;
    		for(int16_t k = 0; k < n; ++k) if(v[i][k] != v[j][k]) ++r;
    		tablo[i][j] = tablo[j][i] = curent[r];
    	}
    }
    for(int16_t i = 0; i < q; ++i)
    {
    	for(int16_t j = 0; j < q; ++j)
    	{
    		cout << tablo[i][j] << ' ';
    	}
    	cout << '\n';
    }
    for(int16_t i = 0; i <= n; ++i) delete [] window[i];
    delete [] window;
    delete [] curent;
    delete [] last;
	return 0;
}