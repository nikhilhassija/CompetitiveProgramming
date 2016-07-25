#include <bits/stdc++.h>

#define pii pair <int, int>

using namespace std;

char A[25][25];
int V[25][25];
string S[25][25];
int ci,cj;
int n,m;

void make(int, int);
int good(int, int);
pii go(int, int, string);

int main()
{
	cin>>n>>m;

	for(int i=0;i<n;i++)
		scanf("%s",A[i]);

	memset(V,1,sizeof(V));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(A[i][j] == 'C')
			{
				ci = i;
				cj = j;
			}
			if(A[i][j] == '.')
				V[i][j] = 0;
		}
	}

	S[ci][cj] = "";
	make(ci,cj);

	string ans = "";

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(A[i][j] == '.')
			{
				pii p = go(i,j,ans);

				if(p.first == -1 && p.second == -1)
					continue;
				else
				{
					int x = p.first;
					int y = p.second;

					ans += S[x][y];
				}
			}
		}
	}

	cout<<ans<<endl;
}

void make(int x, int y)
{
	V[x][y] = 1;

	queue < pii > Q;
	Q.push(make_pair(x,y));

	while(!Q.empty())
	{
		pii p = Q.front();
		x = p.first;
		y = p.second;
		Q.pop();

		if(good(x-1,y) && V[x-1][y] == 0)//u
		{
			S[x-1][y] = 'D' + S[x][y];
			V[x-1][y] = 1;
			Q.push(make_pair(x-1,y));
		}

		if(good(x+1,y) && V[x+1][y] == 0)//d
		{
			S[x+1][y] = 'U' + S[x][y];
			V[x+1][y] = 1;
			Q.push(make_pair(x+1,y));
		}

		if(good(x,y-1) && V[x][y-1] == 0)//l
		{
			S[x][y-1] = 'R' + S[x][y];
			V[x][y-1] = 1;
			Q.push(make_pair(x,y-1));
		}

		if(good(x,y+1) && V[x][y+1] == 0)//r
		{
			S[x][y+1] = 'L' + S[x][y];
			V[x][y+1] = 1;
			Q.push(make_pair(x,y+1));
		}
	}
}

int good(int x, int y)
{
	return x>0 && y>=0;
}

pii go(int x, int y, string S)
{
	for(int i=0;i<S.size();i++)
	{
		switch(S[i])
		{
			case 'U': if(A[x-1][y] != '*') x--;break;
			case 'D': if(A[x+1][y] != '*') x++;break;
			case 'L': if(A[x][y-1] != '*') y--;break;
			case 'R': if(A[x][y+1] != '*') y++;break;
		}

		if(x == ci && y == cj)
			return make_pair(-1,-1);
	}

	return make_pair(x,y);	
}