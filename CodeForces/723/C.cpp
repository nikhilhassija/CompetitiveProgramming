#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;

	int A[n];
	for(int i=0;i<n;i++)
		cin >> A[i];

	for(int i=0;i<n;i++)
		A[i]--;

	int B[m];
	memset(B,0,sizeof(B));
	for(int i=0;i<n;i++)
		if(A[i] < m)
			B[A[i]]++;

	int ans = n/m;
	int change = 0;
	int a = ans;

	for(int i=0;i<m;i++)
	{
		int j = 0;
		if(B[i] < a)
		{
			for(;j<n && B[i] < a;j++)
			{
				if(A[j] >= m)
				{
					A[j] = i;
					B[i]++;

					change++;
				}
				else if(B[A[j]] > a)
				{
					B[A[j]]--;
					B[i]++;

					A[j] = i;
					change++;
				}
			}
		}
	}

	printf("%d %d\n",ans,change);
	for(int i=0;i<n;i++)
		printf("%d ",A[i]+1);
	printf("\n");
}