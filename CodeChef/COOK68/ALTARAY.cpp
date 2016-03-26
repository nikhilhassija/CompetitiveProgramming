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

		vector <int> A(n);

		for(int i=0;i<n;i++)
			cin>>A[i];

		for(int i=0;i<n;i++)
			A[i] = A[i]/abs(A[i]);

		vector <int> DP(n);

		DP[n-1] = 1;
		for(int i=n-2;i>=0;i--)
		{
			if(A[i] == A[i+1])
				DP[i] = 1;
			else
				DP[i] = DP[i+1] + 1;
		}

		for(int i=0;i<n;i++)
			printf("%d ",DP[i]);

		printf("\n");
	}
}