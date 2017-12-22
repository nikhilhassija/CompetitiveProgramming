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
	int k;
	cin >> k;

	if (not k)
	{
		cout << "a" << endl;
		return 0;
	}

	char cur = 'a';

	while (k)
	{
		int x = 0;
		while ((x * (x + 1)) / 2 <= k)
			x++;

		k -= (x * (x - 1)) / 2;

		for (int i = 0; i < x; i++)
			cout << cur;

		cur++;
	}

	cout << endl;
	
	return (0-0);	
}