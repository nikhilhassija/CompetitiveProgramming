#include <bits/stdc++.h>

using namespace std;

const long long int MOD = 1e9 + 7;

long long int binpow(long long int a, long long int b)
{
	long long int res = 1;
	while(b)
	{
		if(b & 1)
			res *= a;
		a *= a;
		b >>= 1;
		a %= MOD;
		res %= MOD;
	}
	return res;
}

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		long long int n,k;
		cin>>n>>k;
		
		long long int res = powmod(k-1,n-1);
		res *= k;
		res %= MOD;
		cout<<res<<endl;
	}
}