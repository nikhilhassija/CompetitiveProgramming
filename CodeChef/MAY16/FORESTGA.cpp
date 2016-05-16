#include <bits/stdc++.h>

#define lli long long int 
#define pll pair <lli,lli>

using namespace std;

bool comp(pll a, pll b)
{
	return a.first < b.first;
}

int main()
{
	lli n,w,l;
	cin>>n>>w>>l;

	vector <lli> H(n);
	vector <lli> R(n);
	vector <pll> P(n);

	for(lli i=0;i<n;i++)
		cin>>H[i]>>R[i];

	for(lli i=0;i<n;i++)
	{
		if(H[i] >= l)
			P[i].first = 0;
		else
			P[i].first = (l - H[i])/R[i] + ((l - H[i])%R[i] > 0);
		P[i].second = i; 
	}

	sort(P.begin(),P.end(),comp);

	lli t;
	lli m = 2e18;

	lli h = 0;
	lli r = 0;

	for(int i=0;i<n;i++)
	{
		lli x = P[i].second;
		t = P[i].first;

		h += H[x];
		r += R[x];

		lli s = h + t*r;
		if(s >= w)
			m = min(m,t);

		lli u = (w-h)/r + ((w-h)%r > 0);

		if(u >= t)
			m = min(m,u);

		// printf("x-%lld t-%lld h-%lld r-%lld s-%lld u-%lld m-%lld\n",x,t,h,r,s,u,m);
	} 

	cout<<m<<endl;
}