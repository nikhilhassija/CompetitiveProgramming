#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n,k;
		cin>>n>>k;

		int A[n];
		for(int i=0;i<n;i++)
			cin>>A[i];

		for(int i=0;i<n;i++)
			A[i]--;

		int C[101];
		memset(C,0,sizeof(C));
		for(int i=0;i<n;i++)
			C[A[i]]++;

		for(int i=0;i<n;i++)
			if(A[i] == i)
				C[i] -= 1000;

		int ans = 0;
		for(int i=0;i<101;i++)
			if(C[i] >= k)
				ans++;

		printf("%d\n", ans);
	}
}