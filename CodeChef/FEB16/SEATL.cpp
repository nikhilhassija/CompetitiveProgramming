#include <bits/stdc++.h>

using namespace std;

int n,m;
int mx=0;
int rs=0;

vector < vector <int> > A;
vector < vector <int> > X1;
vector < vector <int> > Y1;
vector < vector < pair<int,int> > > X;
vector < vector < pair<int,int> > > Y;

void work(int i, int j)
{
	int P[n+m];

	int x=0;
	int y=0;	

	int res = 0;
	while(x<X[i].size() && y<Y[j].size())
	{
		if(X[i][x].first == Y[j][y].first)
		{
			res = X[i][x].second + Y[j][y].second;
			if(A[i][j] == X[i][x].first)
				res--;
			x++;
			y++;
		}
		else
		{
			res = max(X[i][x].second,Y[j][y].second);
			if(X[i][x]<Y[j][y])
				x++;
			else
				y++;
		}
		rs = max(rs,res);
	}
	while(x<X[i].size())
	{
		rs = max(rs,X[i][x].second);
		x++;
	}
	while(y<Y[j].size())
	{
		rs = max(rs,Y[j][y].second);
		y++;
	}
}

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		A.clear();
		X1.clear();
		Y1.clear();
		X.clear();
		Y.clear();

		cin>>n>>m;

		A.resize(n);
		X1.resize(n);
		Y1.resize(m);
		X.resize(n);
		Y.resize(m);

		for(int i=0;i<n;i++)
		{
			A[i].resize(m);
			X1[i].resize(m);
		}
		for(int i=0;i<m;i++)
		{
			Y1[i].resize(n);
		}

		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>A[i][j];
		
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				X1[i][j] = A[i][j];

		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				Y1[j][i] = A[i][j];
		
		for(int i=0;i<n;i++)
			sort(X1[i].begin(),X1[i].end());

		for(int i=0;i<m;i++)
			sort(Y1[i].begin(),Y1[i].end());

		for(int i=0;i<n;i++)
		{
			int c = 1;
			for(int j=1;j<m;j++)
			{
				if(X1[i][j]==X1[i][j-1])
					c++;
				else
				{
					X[i].push_back(make_pair(X1[i][j-1],c));
					c = 1;
				}
			}
			X[i].push_back(make_pair(X1[i][m-1],c));		
		}

		for(int i=0;i<m;i++)
		{
			int c = 1;
			for(int j=1;j<n;j++)
			{
				if(Y1[i][j]==Y1[i][j-1])
					c++;
				else
				{
					Y[i].push_back(make_pair(Y1[i][j-1],c));
					c = 1;
				}
			}
			Y[i].push_back(make_pair(Y1[i][m-1],c));		
		}


		/*
		for(int i=0;i<m;i++)
		{
			int c=1;
			for(int j=1;j<n;j++)
			{
				if(Y1[j][i] == Y1[j-1][i])
					c++;
				else
				{
					Y[i].push_back(make_pair(Y1[j-1][i],c));
					c = 1;
				}
			}
			Y[i].push_back(make_pair(Y1[n-1][i],c));
		}
		*/

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				work(i,j);
			}		
		}
		cout<<rs<<endl;
	}
}