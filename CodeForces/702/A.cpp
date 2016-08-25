#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;

	int A[n];
	for(int i=0;i<n;i++)
		cin>>A[i];

	int ans = 0;
	int temp = 1;
	for(int i=1;i<n;i++)
	{
		if(A[i] > A[i-1])
			temp++;
		else
		{
			ans = max(ans,temp);
			temp = 1;
		}
	}
	ans = max(ans,temp);

	printf("%d\n",ans);
}