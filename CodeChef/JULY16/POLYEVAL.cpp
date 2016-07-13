#include <bits/stdc++.h>

#define lli long long int

using namespace std;

const lli MOD = 786433;

int main()
{
	lli n;
	cin>>n;	
	n++;

	lli A[n];
	for(lli i=0;i<n;i++)
		cin>>A[i];

	lli q;
	cin>>q;
	
	while(q--)
	{
		lli x;
		cin>>x;
		
		lli ans = 0;
		lli mul = 1;

		for(lli i=0;i<n;i++)
		{
			ans += mul*A[i];
			ans %= MOD;

			mul *= x;
			mul %= MOD;
		}

		printf("%lld\n",ans);
	}
}