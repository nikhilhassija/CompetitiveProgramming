#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))
#define fastio() ios_base::sync_with_stdio(0); cin.tie(NULL)

using namespace std;

int N[10][2];

void init();

void carry(int *, int *, int);

int main()
{
	init();

	lli n;
	cin >> n;

	int d = log10(n);

	int C[d + 1];
	mset(C);
	for(int i = 1; i <= d; i++)
		cin >> C[i];

	int D[d + 1];
	lli x = n;
	for(int i = d; i >= 0; i--)
	{
		D[i] = x % 10;
		x /= 10;
	}

	lli ans = 1;
	for(int i = d; i > 0; i--)
	{
		cout << D[i] << " " << C[i] << endl;
		cout << N[D[i]][C[i]] << endl;
		ans *= N[D[i]][C[i]];

		D[i - 1] -= C[i];
		carry(D, C, d);
	}

	ans *= N[D[0]][0];

	cout << ans << endl;

	return (0-0);	
}

void init()
{
	mset(N);

	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++)
			N[(i + j) % 10][(i + j) / 10] ++;

	for(int i = 0; i < 10; i++)
		cout << i << " -- " <<N[i][0] << " " << N[i][1] << endl;
}

void carry(int * D, int * C, int n)
{
	for(int i = n; i > 0; i--)
	{
		if(D[i] < 0)
		{
			if(C[i - 1])
			{
				C[i - 1] = 0;
				D[i] += 10;
			}
			else
			{
				D[i - 1]--;
				D[i] += 10;
			}
		}
	}
}