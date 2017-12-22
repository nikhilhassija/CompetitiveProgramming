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

const int MAX_N = 1e6;

set <int> S;

void make_num();

int main()
{
	make_num();

	int n;
	cin >> n;

	int ans = 1;

	for (int i = 1; i <= sqrt(n); i++)
	{
		if (n % i)
			continue;

		if (S.find(i) != S.end())
			ans = max(ans, i);

		if (S.find(n / i) != S.end())
			ans = max(ans, n / i);
	}

	cout << ans << endl;
	
	return (0-0);	
}

void make_num()
{
	for (int k = 1; k < 15; k++)
	{
		int n = (1 << (2 * k - 1)) - (1 << (k - 1));

		if (n > MAX_N)
			break;

		S.insert(n);
	}
}