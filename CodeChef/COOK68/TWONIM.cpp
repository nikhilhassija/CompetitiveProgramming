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

		int X[n];
		int A[n+1][10];
		memset(A,0,sizeof(A));

		for(int i=0;i<n;i++)
			cin>>X[i];

		for(int i=0;i<n;i++)
		{
			int x = X[i];
			for(int j=0;j<10;j++)
			{
				A[i][j] = x%2;
				x = x>>1;
			}
		}

		for(int i=0;i<10;i++)
		{
			int x = 0;
			for(int j=0;j<n;j++)
				x += A[j][i];
			A[n][i] = x;
		}

		int turn = 1;

		while(1)
		{
			int x = 0;

			for(int i=0;i<10;i++)
				x += A[n][i]%2;

			if(x == 0)
				break;
			else
			{
				x = 10;
				for(int i=0;i<10;i++)
				{
					if(A[n][i] && A[n][i]%2 == 0)
					{
						x = i;
						break;
					}
				}
				if(x == 10)
				{
					for(int i=0;i<10;i++)
						if(A[n][i])
							x = i;
				}

				for(int i=0;i<n;i++)
				{
					if(A[i][x])
					{
						x = i;
						break;
					}
				}

				for(int i=0;i<10;i++)
					A[x][i] = 0;

				for(int i=0;i<10;i++)
				{
					x = 0;
					for(int j=0;j<n;j++)
						x += A[j][i];
					A[n][i] = x;
				}
			}

			turn ^= 1;
		}

		if(turn)
			printf("First\n");
		else
			printf("Second\n");	
	}
}