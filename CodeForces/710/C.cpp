#include <bits/stdc++.h>

using namespace std;

int A[50][50] = {0};

void solve(int);

int main()
{
	int n;
	cin>>n;

	solve(n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d ",A[i][j]);
		printf("\n");
	}
}

void solve(int n)
{
	int x = n/2;
	int y = n-1;

	int a = 1;
	while(a <= n*n)
	{
		if(x < 0 && y == n)
		{
			y -= 2;
			x++;
		}
		else
		{
			y %= n;
			x = max(x,x+n)%n;
		}

		if(A[x][y])
		{
			y -= 2;
			x++;
			continue;	
		}
		else
		{
			// printf("%d - %d %d\n",a,x,y);
			A[x][y] = a;
			a++;
		}

		x--;
		y++;
	}	
}