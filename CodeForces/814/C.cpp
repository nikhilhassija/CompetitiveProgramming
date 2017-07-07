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

string S;

int check(int, char, int);

int main()
{
	int n;
	cin >> n;

	cin >> S;

	int q;
	cin >> q;

	while(q--)
	{
		int k;
		char c;
		cin >> k >> c;

		int ans = 0;

		int l = 0;
		int r = n;

		while(l <= r)
		{
			int m = (l + r) / 2;

			if(check(m, c, k))
			{
				ans = max(ans, m);
				l = m+1;
			}
			else
				r = m-1;
		}

		cout << ans << endl;
	}

	return (0-0);
}

int check(int l, char c, int k)
{
	int n = S.size();

	int x = 0;
	for(int i=0; i<l-1; i++)
		x += (S[i] != c);

	for(int i=0; i<=n-l; i++)
	{
		x += (S[i+l-1] != c);

		if(x <= k)
			return 1;

		x -= (S[i] != c);
	}

	return 0;
}