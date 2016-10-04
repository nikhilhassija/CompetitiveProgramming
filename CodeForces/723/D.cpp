#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;

	int A[n+4][m+4];
	memset(A,0,sizeof(A));
	for(int i=1;i<n+3;i++)
	{
		A[i][1] = -1;
		A[i][m+2] = -1;
	}

	for(int i=1;i<m+2;i++)
	{
		A[1][i] = -1;
		A[n+2][i] = -1;
	}

	string S[n];
	for(int i=0;i<n;i++)
		cin >> S[i];

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(S[i][j] == '.')
				A[i+2][j+2] = 1;

	int V[n+4][m+4];
	memset(V,0,sizeof(V));

	queue < pair<int,int> > Q;
	Q.push({1,1});

	while(!Q.empty())
	{
		auto p = Q.front();
		Q.pop();

		if(V[p.first][p.second])
			continue;
		else
			V[p.first][p.second] = 1;

		for(int i=-1;i<=1;i++)
		{
			if(A[p.first + i][p.second] == 1)
				A[p.first + i][p.second] = -1;
			
			if(A[p.first + i][p.second] == -1 && !V[p.first + i][p.second])
				Q.push({p.first + i,p.second});
		}

		for(int i=-1;i<=1;i++)
		{
			if(A[p.first][p.second + i] == 1)
				A[p.first][p.second + i] = -1;
			
			if(A[p.first][p.second + i] == -1 && !V[p.first][p.second + i])
				Q.push({p.first,p.second + i});
		}

	}

	int l = 2;
	int L[2500];
	memset(L,0,sizeof(L));

	for(int i=0;i<n+4;i++)
	{
		for(int j=0;j<m+4;j++)
		{
			if(A[i][j] == 1)
			{
				queue < pair<int,int> > Q;
				Q.push({i,j});

				while(!Q.empty())
				{
					auto p = Q.front();
					Q.pop();

					if(A[p.first][p.second] == l)
						continue;
					else
					{
						A[p.first][p.second] = l;
						L[l]++;
					}

					for(int i=-1;i<=1;i++)
					{
						if(A[p.first + i][p.second] == 1)
							Q.push({p.first + i,p.second});
					}

					for(int i=-1;i<=1;i++)
					{
						if(A[p.first][p.second + i] == 1)
							Q.push({p.first,p.second + i});
					}

				}

				l++;
			}
		}
	}

	vector < pair <int, int> > B;

	for(int i=2;i<l;i++)
		B.push_back({L[i],i});

	sort(B.begin(),B.end());
	
	int ans = 0;
	for(int x=0;x<(l-k-2);x++)
	{
		ans += B[x].first;

		for(int i=0;i<n+4;i++)
			for(int j=0;j<m+4;j++)
				if(A[i][j] == B[x].second)
					A[i][j] = 0;				
	}

	printf("%d\n",ans);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(A[i+2][j+2])
				cout << '.';
			else
				cout << '*';
		}
		printf("\n");
	}
}

