#include <bits/stdc++.h>

#define lli long long int 

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		lli n;
		cin>>n;

		if(!n)
		{
			printf("0\n");
			continue;
		}

		lli ans = 0;

		lli m = (n+1)/2;

		ans += 2*m;

		m = (n-1)/3 + 1;
		ans -= m/2;

		printf("%lld\n",ans);
	}
}