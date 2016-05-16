#include <bits/stdc++.h>

using namespace std;

const long long int mod = 1e9 + 7;

bool inrange(long long int a, long long int b, long long int c)
{
	return (a <= b) && (b < c);
}

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		long long int n,m,s;
		cin>>n>>m>>s;

		long long int A[m+1][n];
		memset(A,0,sizeof(A));

		A[0][s-1] = 1;

		long int P[m];

		for(int i=0;i<m;i++)
			cin>>P[i];

		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(inrange(0,j+P[i],n))
				{
					A[i+1][j+P[i]] += A[i][j];
					A[i+1][j+P[i]] %= mod;
				}
				
				if(inrange(0,j-P[i],n))
				{
					A[i+1][j-P[i]] += A[i][j];
					A[i+1][j-P[i]] %= mod;
				}
			}
		}

		for(int j=0;j<n;j++)
			printf("%lld ",A[m][j]);
		printf("\n");
	}
}