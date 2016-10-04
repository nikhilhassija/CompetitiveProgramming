#include <bits/stdc++.h>

// #define pii pair <int,int>

using namespace std;

struct pii
{
	int first,second;
};

vector <vector <vector <pii> > > DP;

int main()
{
	int n,s,m;
	cin >> n >> s >> m;

	int A[3];
	memset(A,0,sizeof(A));

	while(m--)
	{
		int x;
		cin >> x;

		A[x-1]++;
	}

	// pii DP[A[0]+1][A[1]+1][A[2]+1];
	// memset(DP,0,sizeof(0));
	
	DP.resize(A[0]+1);
	for(int i=0;i<=A[0];i++)
	{
		DP[i].resize(A[1]+1);

		for(int j=0;j<=A[1];j++)
			DP[i][j].resize(2);
	}


	DP[0][0][0] = {0,0};
	
	for(int i=1;i<A[0];i++)
	{
		auto p = DP[i-1][0][0];
		p.second += 1;
		if(p.second >= s)
		{
			p.first++;
			p.second = 0;
		}

		DP[i][0][0] = p;
	} 

	for(int i=1;i<=A[1];i++)
	{
		auto p = DP[0][i-1][0];
		p.second += 2;
		if(p.second >= s)
		{
			p.first++;
			p.second = 0;
		}

		DP[0][i][0] = p;
	} 
	
	DP[0][0].resize(A[2]+1);

	for(int i=1;i<=A[2];i++)
	{
		auto p = DP[0][0][i-1];
		p.second += 3;
		if(p.second >= s)
		{
			p.first++;
			p.second = 0;
		}

		DP[0][0][i] = p;
	} 

	for(int i=0;i<=A[0];i++)
	{
		for(int j=0;j<=A[1];j++)
		{
			DP[i][j].resize(A[2]+1);
			
			for(int k=0;k<=A[2];k++)
			{
				if(i)
				{
					auto p = DP[i-1][j][k];

					p.second += 1;

					if(p.second >= s)
					{
						p.second = 0;
						p.first++;
					}

					if(p.first > DP[i][j][k].first)
						DP[i][j][k] = p;
					else if(p.first == DP[i][j][k].first && p.second > DP[i][j][k].second)
						DP[i][j][k] = p;
				}

				if(j)
				{
					auto p = DP[i][j-1][k];

					p.second += 2;

					if(p.second >= s)
					{
						p.second = 0;
						p.first++;
					}

					if(p.first > DP[i][j][k].first)
						DP[i][j][k] = p;
					else if(p.first == DP[i][j][k].first && p.second > DP[i][j][k].second)
						DP[i][j][k] = p;
				}

				if(k)
				{
					auto p = DP[i][j][k-1];

					p.second += 3;

					if(p.second >= s)
					{
						p.second = 0;
						p.first++;
					}

					if(p.first > DP[i][j][k].first)
						DP[i][j][k] = p;
					else if(p.first == DP[i][j][k].first && p.second > DP[i][j][k].second)
						DP[i][j][k] = p;
				}

				if(DP[i][j][k].first == n)
				{
					printf("%d\n",n);
					return 0;
				}
			}
		}
		if(i > 1)
		{
			DP[i-2].resize(0);
			DP[i-2].shrink_to_fit();
		}
	}	

	auto p = DP[A[0]][A[1]][A[2]];

	printf("%d\n",p.first);
}
