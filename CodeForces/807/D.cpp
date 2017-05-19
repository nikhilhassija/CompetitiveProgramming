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

int score(int, int);

int main()
{
	int n;
	cin >> n;

	int S[n][5];

	for(int i=0; i<n; i++)
		for(int j=0; j<5; j++)
			cin >> S[i][j];

	int better[5];
	mset(better);

	for(int i=0; i<5; i++)
	{
		if(S[0][i] == -1)
			better[i] = 0;
		else if(S[1][i] == -1)
			better[i] = 1;
		else if(S[0][i] > S[1][i])
			better[i] = 1;
	}	

	int cheat[5];
	for(int i=0; i<5; i++)
		cheat[i] = better[i] && (S[0][i] != -1);

	int sum_cheat = 0;
	for(int i=0; i<5; i++)
		sum_cheat += cheat[i];

	if(sum_cheat == 0)
	{
		cout << -1 << endl;
		return 0;
	}

	int solve[5];
	mset(solve);

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<5; j++)
		{
			solve[j] += (S[i][j] != -1);
			S[i][j] += 251 * (S[i][j] == -1);
		}
	}

	int v, p;




	for(int i=0; i<500; i++)
	{
		v = 0; p = 0;

		for(int j=0; j<5; j++)
		{
			int s = score(solve[j] + (cheat[j] * i), n + i);
			
			cout << s << " ";

			v += (250 - S[0][j]) * s;
			p += (250 - S[1][j]) * s;
		}

		printf("%d %d\n", v, p);

		if(v > p)
		{
			cout << i << endl;
			return 0;
		}
	}

	cout << -1 << endl;

	return (0-0);	
}

int score(int s, int t)
{
	if(2*s > t)
		return 2;

	if(4*s > t)
		return 4;

	if(8*s > t)
		return 6;

	if(16*s > t)
		return 8;

	if(32*s > t)
		return 10;

	return 12;
}