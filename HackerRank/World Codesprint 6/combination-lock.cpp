#include <bits/stdc++.h>

using namespace std;

int main()
{
	int A[5],B[5],C[5];
	int n = 5;

	for(int i=0;i<n;i++)
		cin>>A[i];

	for(int i=0;i<n;i++)
		cin>>B[i];

	int ans = 0;
	for(int i=0;i<n;i++)
	{
		int d = abs(A[i]-B[i]);
		ans += min(10-d,d);
	}

	printf("%d\n",ans);
}