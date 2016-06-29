#include <bits/stdc++.h>

using namespace std;

struct mypair
{
	int n[2];
}; 

int main()
{
	int n,m;
	cin>>n>>m;

	char A[n][m];
	int S[n][m];
	mypair P[n][m];
	memset(P,0,sizeof(P));

	for(int i=0;i<n;i++)
		scanf("%s",A[i]);

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			A[i][j] -= '0';

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			S[i][j] = A[i][j];

	for(int i=0;i<n;i++)
		for(int j=1;j<m;j++)
			S[i][j] += S[i][j-1];

	for(int i=1;i<n;i++)
		for(int j=0;j<m;j++)
			S[i][j] += S[i-1][j];

	P[0][0].n[S[0][0]%2] = 1;
	for(int i=1;i<m;i++)
	{
		P[0][i].n[0] += P[0][i-1].n[0];
		P[0][i].n[1] += P[0][i-1].n[1];
		P[0][i].n[S[0][i]%2]++;
	}

	for(int i=1;i<n;i++)
	{
		P[i][0].n[0] += P[i-1][0].n[0];
		P[i][0].n[1] += P[i-1][0].n[1];
		P[i][0].n[S[i][0]%2]++;
	}

	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			P[i][j].n[0] = P[i][j-1].n[0] + P[i-1][j].n[0] - P[i-1][j-1].n[0]; 
			P[i][j].n[1] = P[i][j-1].n[1] + P[i-1][j].n[1] - P[i-1][j-1].n[1]; 
			P[i][j].n[S[i][j]%2]++;
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			// printf("%d(%d,%d)\t",A[i][j],P[i][j].n[0],P[i][j].n[1]);
		}
		// printf("\n");
	}

	int ans = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int s = S[n-1][m-1];
			if(i)
				s -= S[i-1][j];
			if(j)
				s -= S[i][j-1];
			if(i && j)
				s += S[i-1][j-1];

			int N[2];
			N[0] = P[n-1][m-1].n[0];
			N[1] = P[n-1][m-1].n[1];
			if(i)
			{
				N[0] -= P[i-1][j].n[0];
				N[1] -= P[i-1][j].n[1];
			}
			if(j)
			{
				N[0] -= P[i][j-1].n[0];
				N[1] -= P[i][j-1].n[1];
			}
			if(i && j)
			{
				N[0] += P[i-1][j-1].n[0];
				N[1] += P[i-1][j-1].n[1];
			}


			if(s%2 == S[n-1][m-1]%2)
				ans += N[0];
			else
				ans += N[1];

			printf("%d,%d = %d\n",i,j,ans);
		}
	}
	printf("%d\n",ans);
}