#include <bits/stdc++.h>

using namespace std;

const long long int MAX_N = 1e5 + 5;
const long long int MOD   = 1e9 + 7;

long long int inv(long long int);
long long int powmod(long long int,long long int);

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		long long int n,k;
		scanf("%lld %lld",&n,&k);

		long long int A[n];
		for(long long int i=0;i<n;i++)
			scanf("%lld",&A[i]);

		long long int x = 0;
		for(long long int i=0;i<n;i++)
			if(A[i] != 0)
				x++;

		long long int sum = 0;
		long long int prod = 1;
		if(x == n)
		{
			sum = 1 + (k%2)*(n-1);
			prod = 1 + (k%2)*(n-1);

			for(long long int i=2+(k%2);i<=k && i<=n;i+=2)
			{
				prod *= (n+1) - i;
				prod %= MOD;
				prod *= (n+1) - (i-1);
				prod %= MOD;
				prod *= inv(i);
				prod %= MOD;
				prod *= inv(i-1);
				prod %= MOD;

				sum += prod;
				sum %= MOD; 
			}
		}
		else
		{
			sum = 1;
			long long int prod = 1;
			for(long long int i=1;i<=k && i<=n;i++)
			{
				prod *= (x+1) - i;
				prod %= MOD;
				prod *= inv(i); 
				prod %= MOD;

				sum += prod;
				sum %= MOD;
			}
		}

		printf("%lld\n",sum);
	}
}

long long int inv(long long int x)
{
	return powmod(x,MOD-2);
}

long long int powmod(long long int a, long long int b)
{
	long long int ans = 1;

	while(b)
	{
		if(b & 1)
		{
			ans *= a;
			ans %= MOD;
		}

		a *= a;
		a %= MOD;
		b /= 2;
	}

	return ans;
}