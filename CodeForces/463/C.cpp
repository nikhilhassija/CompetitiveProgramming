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

int main()
{
	fastio();
	
	int n;
	cin >> n;

	lli A[n][n];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> A[i][j];

	lli D1[2 * n], D2[2 * n];
	mset(D1);	
	mset(D2);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			D1[i + j] += A[i][j];
			D2[n + i - j] += A[i][j]; 
		}


	pair <lli, pii> l = {-1, {0, 0}};
	pair <lli, pii> r = {-1, {0, 0}};

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if((i + j) % 2)
			{
				lli s = D1[i + j] + D2[n + i - j] - A[i][j];

				if(l.first <= s)
					l = {s, {i + 1, j + 1}};
			}
			else
			{
				lli s = D1[i + j] + D2[n + i - j] - A[i][j];

				if(r.first <= s)
					r = {s, {i + 1, j + 1}};
			}
		}
	}

	cout << l.first + r.first << endl;
	cout << l.second.first << " " << l.second.second << " " << r.second.first << " " << r.second.second << endl;

	return (0-0);	
}