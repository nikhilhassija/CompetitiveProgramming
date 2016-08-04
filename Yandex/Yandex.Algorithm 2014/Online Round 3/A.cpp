#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long int NC2[100005];
	for(long long int i=0;i<100005;i++)
		NC2[i] = (i*(i-1))/2;

	int n;
	cin>>n;

	int A[100005];
	memset(A,0,sizeof(A));

	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;

		A[x]++;
		A[y]++;
	}

	long long int ans = 0;
	for(int i=0;i<=n;i++)
		ans += NC2[A[i]];

	cout<<ans<<endl;
}