/*
ID: nikhil14
PROG: combo
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("combo.in","r",stdin);
	freopen("combo.out","w",stdout);
	int n,a,b,c,i,j,k;
	cin>>n;
	int A[n][n][n];
	memset(A,0,sizeof(A));
	cin>>a>>b>>c;
	a--;
	b--;
	c--;
	for(i=a-2;i<=a+2;i++)
	{
		for(j=b-2;j<=b+2;j++)
		{
			for(k=c-2;k<=c+2;k++)
			{
				int x=i,y=j,z=k;
				if(x<0)
					x += n;
				if(y<0)
					y += n;
				if(z<0)
					z += n;
				if(x>=n)
					x -= n;
				if(y>=n)
					y -= n;
				if(z>=n)
					z -= n;
				// cout<<x<<" "<<y<<" "<<z<<endl;
				A[x][y][z] = 1;
			}
		}
	}
	cin>>a>>b>>c;
	a--;
	b--;
	c--;
	for(i=a-2;i<=a+2;i++)
	{
		for(j=b-2;j<=b+2;j++)
		{
			for(k=c-2;k<=c+2;k++)
			{
				int x=i,y=j,z=k;
				if(x<0)
					x += n;
				if(y<0)
					y += n;
				if(z<0)
					z += n;
				if(x>=n)
					x -= n;
				if(y>=n)
					y -= n;
				if(z>=n)
					z -= n;
				// cout<<x<<" "<<y<<" "<<z<<endl;
				A[x][y][z] = 1;
			}
		}
	}
	int count = 0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			for(k=0;k<n;k++)
				count += A[i][j][k];
	cout<<count<<endl;
}