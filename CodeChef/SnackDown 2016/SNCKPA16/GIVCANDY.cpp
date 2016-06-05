#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		long long int a,b,c,d;
		cin>>a>>b>>c>>d;

		long long int g = __gcd(c,d);
		long long int x = abs(a-b)%g;
		long long int ans = min(x,g-x);
		printf("%lld\n",ans);
	}
}