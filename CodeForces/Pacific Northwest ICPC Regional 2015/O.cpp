#include <bits/stdc++.h>

#define pii pair <int,int>

using namespace std;

int m,n;
vector <string> S;
vector < vector<int> > A;

void bfs();
int isgood(int, int);

int main()
{
	cin>>m>>n;

	S.resize(m);
	for(int i=0;i<m;i++)	
		cin>>S[i];

	for(int j=0;j<m;j++)
		for(int i=0;i<n;i++)
			S[j][i] -= '0';

	A.resize(m);
	for(int i=0;i<m;i++)
		A[i].resize(n,0);

	bfs();

	if(A[m-1][n-1])
		printf("%d\n",A[m-1][n-1]-1);
	else
		printf("IMPOSSIBLE\n");
}

void bfs()
{
	queue < pii > Q;
	Q.push(make_pair(0,0));
	A[0][0] = 1;

	while(!Q.empty())
	{
		pii p = Q.front();
		Q.pop();

		int x = p.first;
		int y = p.second;
		int k = S[x][y];
		int d = A[x][y];
		int a,b;

		a = x+k;
		b = y;
		if(isgood(a,b))
		{
			if(A[a][b] == 0)
			{
				A[a][b] = d + 1;
				Q.push(make_pair(a,b));
			}
			else
			{
				A[a][b] = min(A[a][b],d+1);
			}
		}

		a = x-k;
		b = y;
		if(isgood(a,b))
		{
			if(A[a][b] == 0)
			{
				A[a][b] = d + 1;
				Q.push(make_pair(a,b));
			}
			else
			{
				A[a][b] = min(A[a][b],d+1);
			}
		}

		a = x;
		b = y+k;
		if(isgood(a,b))
		{
			if(A[a][b] == 0)
			{
				A[a][b] = d + 1;
				Q.push(make_pair(a,b));
			}
			else
			{
				A[a][b] = min(A[a][b],d+1);
			}
		}

		a = x;
		b = y-k;
		if(isgood(a,b))
		{
			if(A[a][b] == 0)
			{
				A[a][b] = d + 1;
				Q.push(make_pair(a,b));
			}
			else
			{
				A[a][b] = min(A[a][b],d+1);
			}
		}
	}
}

int isgood(int a, int b)
{
	if(a < 0 || !(a < m) || b < 0 || !(b<n))
		return false;
	return true;
}