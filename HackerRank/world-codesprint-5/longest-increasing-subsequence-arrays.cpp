#include <bits/stdc++.h>

#define lli long long int 

using namespace std;

const lli MOD = 1e9 + 7;
const lli N   = 1e5 + 5;

lli V[N];
lli DP[10005][1005];

lli work(int, int, int, int);

int main()
{
	lli p;
	cin>>p;

	while(p--)
	{
		lli n,m;
		cin>>m>>n;

		memset(V,0,sizeof(V));
		memset(DP,int(-1),sizeof(DP));

		printf("%lld\n",work(0,0,m,n));
	}
}

lli work(int cm, int cn, int m, int n)
{
	if(cm == m)
	{
		if(cn == n)
			return 1;
		else
			return 0;
	}

	lli ans = 0;

	if(DP[cm][cn] != -1)
		return DP[cm][cn];

	for(int i=1;i<=n;i++)
	{
		int x = V[i];

		if(i == cn + 1)
		{
			V[i] = 1;
			ans += work(cm+1,cn+1,m,n);
			ans %= MOD;
		}
		else
		{
			ans += work(cm+1,cn,m,n);
			ans %= MOD;
		}

		V[i] = x;
	}

	return DP[cm][cn] = ans%MOD;
}