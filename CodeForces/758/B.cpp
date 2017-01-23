#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))
#define fastio() ios_base::sync_with_stdio(0)

using namespace std;

int main()
{
	string S;
	cin >> S;

	int n = S.size();
	int DP[n+10][4];
	mset(DP);


	for(int i=0; i<n; i++)
	{
		if(S[i] != '!')
		{
			int y;

			switch(S[i])
			{
				case 'R': y=0; break;
				case 'B': y=1; break;
				case 'Y': y=2; break;
				case 'G': y=3; break;
			}

			for(int j = 0; j < 7; j++)
				DP[i + j][y] = 1;
		}
	}

	int A[4];
	mset(A);

	for(int i=0; i<n; i++)
	{
		if(S[i] == '!')
		{
			for(int j=0; j<4;j++)
				A[j] += 1 ^ DP[i+3][j];
		}
	}

	printf("%d %d %d %d\n", A[0], A[1], A[2], A[3]);
}