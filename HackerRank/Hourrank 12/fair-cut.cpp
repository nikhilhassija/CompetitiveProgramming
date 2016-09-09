#include <bits/stdc++.h>

#define lli long long int

using namespace std;

int main()
{
	lli n,k;
	cin>>n>>k;

	lli A[n];
	for(int i=0;i<n;i++)
		cin>>A[i];

	sort(A,A+n);

	lli l = (n-k)/2;
	lli r = l + k;
	lli m = A[l];

	lli ans = 0;
	for(int i=0;i<l;i++)
		ans += abs(A[i]-m);
	
	for(int i=r;i<n;i++)
		ans += abs(A[i]-m);

	ans *= k;
	printf("%lld\n",ans);
}