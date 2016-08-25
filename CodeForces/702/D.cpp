#include <bits/stdc++.h>

#define lli long long int

using namespace std;

int main()
{
	lli d,k,a,b,t,ans;
	cin>>d>>k>>a>>b>>t;

	if(d <= k)
	{
		ans = d*a;
	}
	else
	{
		ans = k*a;
		d -= k;

		lli ct = (k*a + t);
		lli ft = (k*b);

		if(ct < ft)
		{
			ans += (d/k)*ct;
			d %= k;
			ans += min(t+(d*a),d*b);
		}
		else
		{
			ans += d*b;
		}	
	}

	printf("%lld\n",ans);
}