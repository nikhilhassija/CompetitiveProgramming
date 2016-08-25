#include <bits/stdc++.h>

#define lli long long int
#define pll pair <lli,lli>

using namespace std;

int main()
{
	lli n,m;
	cin>>n>>m;

	vector < pll > A(n+m);
	for(int i=0;i<n;i++)
		cin>>A[i].first;

	for(int i=0;i<m;i++)
		cin>>A[i+n].first;

	m += n;
	for(int i=0;i<m;i++)
		A[i].second = (i >= n);

	n = m;

	sort(A.begin(),A.end());

	lli l = 0;
	lli r = 2e9 + 5;
	lli R = r;
	int V[n];

	while(l <= r)
	{
		lli m = (l+r)/2;

		memset(V,0,sizeof(V));

		lli t = n;
		lli d = -(2e9 + 5);

		for(int i=0;i<n;i++)
		{
			if(A[i].second == 1)
			{
				d = A[i].first + m;
			}

			if(A[i].first <= d)
			{
				t -= (V[i] == 0);
				V[i] = 1;
			}
		}

		d = (2e9 + 5);

		for(int i=n-1;i>=0;i--)
		{
			if(A[i].second == 1)
			{
				d = A[i].first - m;
			}

			if(A[i].first >= d)
			{
				t -= (V[i] == 0);
				V[i] = 1;
			}
		}

		if(t)
			l = m+1;
		else
		{
			r = m-1;
			R = min(R,m);
		}

		// printf("%lld %lld === %lld\n",l,r,R);
	}

	printf("%lld\n",R);
}