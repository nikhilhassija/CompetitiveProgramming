#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int c=1;c<=t;c++)
	{
		long long int n,p;
		cin>>n>>p;
		vector <long long int> A(n);
		for(int i=0;i<n;i++)
			cin>>A[i];
		vector <long long int> S(n+1,0);
		for(int i=1;i<=n;i++)
			S[i] = S[i-1] + A[i-1];
		long long int count = 0;
		for(int i=0;i<n;i++)
		{
			long long int d;
			d = distance(S.begin()+i,upper_bound(S.begin()+i,S.end(),S[i]+p));
			count += d-1;
		}
		printf("Case #%d: %lld\n",c,count); 
	}
}