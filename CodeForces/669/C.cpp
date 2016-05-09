#include <bits/stdc++.h>

using namespace std;

int mod(int x, int n)
{
	while(x < 0)
		x += n;
	return x%n;
}

int main()
{
	int n,m,q;
	cin>>n>>m>>q;

	int R[n];
	int C[m];
	int A[n][m];
	memset(R,0,sizeof(R));
	memset(C,0,sizeof(C));
	memset(A,0,sizeof(A));

	while(q--)
	{
		int a;
		cin>>a;

		if(a == 1)
		{
			int x;
			cin>>x;

			R[x-1]++;
			R[x-1] %= n;
		}
		else if(a == 2)
		{
			int x;
			cin>>x;

			C[x-1]++;
			C[x-1] %= n;
		}
		else if(a == 3)
		{
			int r,c,x;
			cin>>r>>c>>x;

			int i = mod(r-1 + C[c-1],n);
			int j = mod(c-1 + R[r-1],m);

			A[i][j] = x;
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			printf("%d ",A[i][j]);
		printf("\n");
	}
}