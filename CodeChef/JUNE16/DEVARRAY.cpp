#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, q;	
	cin>>n>>q;

	int A[n];

	for(int i=0;i<n;i++)
		cin>>A[i];

	int mn = A[0];
	int mx = A[0];
	for(int i=0;i<n;i++)
	{
		mn = min(mn,A[i]);
		mx = max(mx,A[i]);
	}

	while(q--)
	{
		int t;
		cin>>t;

		if(mn <= t && t<=mx)
			printf("Yes\n");
		else
			printf("No\n");
	}
}