#include <bits/stdc++.h>

#define lli long long int

using namespace std;

const lli N = 1e6 + 6;
const lli M = 1e9 + 7;

lli NC2[N];
int A[N][26];

void init();

int main()
{
	ios_base::sync_with_stdio(false);

	string S;
	cin>>S;

	init();

	lli n = S.size();

	memset(A,0,sizeof(A));
	for(int i=0;i<n;i++)
		A[i][S[i]-'a'] = 1;

	for(int i=1;i<n;i++)
		for(int j=0;j<26;j++)
			A[i][j] += A[i-1][j];

	vector <int> P[26];
	for(int i=0;i<n;i++)
		P[S[i]-'a'].push_back(i);

	lli ans = 0;
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<P[i].size();j++)
		{
			for(int k=j+1;k<P[i].size();k++)
			{
				int x = P[i][j];
				int y = P[i][k] - 1;

				for(int l=0;l<26;l++)
				{
					ans += NC2[A[y][l]-A[x][l]];
					ans %= M;
				}
			}
		}
	}

	cout<<ans<<'\n';
}

void init()
{
	for(int i=0;i<N;i++)
		NC2[i] = ((i*(i-1))/2)%M;
}