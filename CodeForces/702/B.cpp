#include <bits/stdc++.h>

#define lli long long int

using namespace std;

int main()
{
	lli P[33];
	P[0] = 1;
	for(int i=1;i<33;i++)
		P[i] = P[i-1] * 2;

	int n;
	cin>>n;

	vector <lli> A(n);
	for(int i=0;i<n;i++)
		cin>>A[i];

	sort(A.begin(),A.end());

	lli ans = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<33;j++)
		{
			if(P[j] - A[i] < A[i])
				continue;
			else
			{
				lli x = P[j] - A[i];
				ans += upper_bound(A.begin()+i+1,A.end(),x) - lower_bound(A.begin()+i+1,A.end(),x);
			}
		}
	}

	printf("%lld\n",ans);
}