#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;

	int A[n];
	for(int i=0;i<n;i++)
		cin>>A[i];

	sort(A,A+n);
	int ans = A[n-1] + A[n-2];

	for(int i=0;i<n/2;i++)
		ans = min(ans,A[i]+A[n-1-i]);

	printf("%d\n",ans);
}