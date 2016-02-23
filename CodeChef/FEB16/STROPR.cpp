#include <bits/stdc++.h>

using namespace std;

const unsigned long long mod = 1e9 + 7;

unsigned long long fast_inv(unsigned long long base)
{
	unsigned long long res = 1;
	unsigned long long pwr = mod - 2;
    while(pwr>0) 
    {
		if(pwr%2)
			res = (res*base) % mod;
		base = (base*base) % mod;
		pwr >>= 1;
    }
    return res%mod;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		unsigned long long n,x,m;
		scanf("%llu %llu %llu",&n,&x,&m);
		x--;
		unsigned long long A[n];	
		for(int i=0;i<n;i++)
			scanf("%llu",&A[i]);
		for(int i=0;i<n;i++)
			A[i] %= mod;
		if(x)
		{
			m = m%mod;
			unsigned long long c = m;
			for(int i=1;i<=x;i++)
			{
				unsigned long long a = (c*A[x-i])%mod;
				A[x] = (A[x] + a)%mod;
				a = (m+i)%mod;
				c = (c*a)%mod;
				a = fast_inv(i+1);
				c = (c*a)%mod;
				// c = (((c*((m+i)%mod))%mod)*fast_inv(i+1))%mod;
			}
		}
		printf("%llu\n",A[x]);
	}
}