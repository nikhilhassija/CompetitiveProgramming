#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n,m;
		cin>>n>>m;

		int A[m];
		string S;
		memset(A,0,sizeof(A));

		while(n--)
		{
			cin>>S;
			for(int i=0;i<m;i++)
				A[i] += (S[i] - '0');
		}

		int sum = 0;
		for(int i=0;i<m;i++)
			sum += A[i]*(A[i]-1);

		printf("%d\n",sum/2);
	}
}