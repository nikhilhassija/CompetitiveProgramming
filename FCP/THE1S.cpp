#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int t,r,c,i,j,x,y;
	vector < vector <int> > A,DP;
	cin>>t;
	while(t--)
	{
		cin>>r>>c;
		A.resize(r);
		DP.resize(r);
		for(i=0;i<r;i++)
		{
			A[i].resize(c);
			DP[i].resize(c);
		}
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
				cin>>A[i][j];

		for(i=0;i<r;i++)
			DP[i][0] = A[i][0];
		for(i=0;i<c;i++)
			DP[0][i] = A[0][i];
		for(i=1;i<r;i++)
			for(j=1;j<c;j++)
				DP[i][j] = (A[i][j])?(min(DP[i-1][j-1],min(DP[i-1][j],DP[i][j-1])) + 1):0;
		x = 0;
		y = 0;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(DP[i][j]>DP[x][y])
				{
					x = i;
					y = j;
				}
			}
		}
		// /*
		for(i=0;i<DP[x][y];i++)
		{
			for(j=0;j<DP[x][y];j++)
				cout<<"1 ";
			cout<<endl;
		}
		// */
	}
	return 0;
}