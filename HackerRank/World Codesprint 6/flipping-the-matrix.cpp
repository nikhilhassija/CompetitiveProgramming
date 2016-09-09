#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;

		int A[2*n][2*n];
		for(int i=0;i<2*n;i++)
			for(int j=0;j<2*n;j++)
				cin>>A[i][j];

		int ans = 0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				int oi = (2*n) - 1 - i;
				int oj = (2*n) - 1 - j;

				ans += max(max(A[i][j],A[i][oj]),max(A[oi][j],A[oi][oj]));
			}
		}

		printf("%d\n",ans);
	}
}