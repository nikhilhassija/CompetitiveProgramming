#include <bits/stdc++.h>

#define lli long long int

using namespace std;

int main()
{
	lli l1,l2,r1,r2,k;
	cin>>l1>>r1>>l2>>r2>>k;

	lli l = max(l1,l2);
	lli r = min(r1,r2);

	lli ans = 0;

	if(l <= r)
	{
		ans = r-l+1;
		if(l <= k && k <= r)
			ans--;
	}

	printf("%lld\n",ans);
}