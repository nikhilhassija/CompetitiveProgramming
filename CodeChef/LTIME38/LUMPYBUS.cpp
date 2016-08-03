#include <bits/stdc++.h>

#define lli long long int 

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		lli n,p,q;
		cin>>n>>p>>q;

		vector <lli> A(n);
		for(lli i=0;i<n;i++)
			cin>>A[i];

		sort(A.begin(),A.end());

		lli ans = 0;
		for(lli i=0;i<n;i++)
		{
			if((p+2*q)>=A[i])
			{
				if((A[i]%2 && p) || A[i]%2 == 0)
				{
					lli sub = min(A[i]/2,q);
					q -= sub;
					A[i] -= 2*sub;
					p -= A[i];
					A[i] = 0;
					ans++;
				}
			}
			// printf("%lld -> %lld %lld \n",i,p,q );
		}

		printf("%lld\n",ans);
	}
}