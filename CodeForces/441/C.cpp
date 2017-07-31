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
	int n, m, k;
	cin >> n >> m >> k;

	int t = 0;
	int i = 0;
	int j = 0;
	int c = 1;

	int A[n][m];
	mset(A);

	int l;

	if(c == k)
		l = n * m;
	else
		l = 2;

	cout << l << " ";

	for(int x = 0; x < n * m; x++)
	{
		A[i][j] = ++t;

		cout << (i + 1) << " " << (j + 1) << " ";
		l--;

		if(l == 0 and c < k)
		{
			c++;

			if(c == k)
				l = n * m - (x + 1);
			else
				l = 2;

			cout << endl << l << " ";
		}

		if(j != m - 1 and not A[i][j + 1])
		{
			j++;
			continue;
		}

		if(j and not A[i][j - 1])
		{
			j--;
			continue;
		}

		i++;
	}

	cout << endl;

	return (0-0);	
}