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
	int n;
	cin >> n;

	int D[n + 1];
	mset(D);

	D[0] = n + 1;

	for(int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;

		D[x] ++;
		D[y] ++;
	}

	sort(D + 1, D + n + 1);

	if(D[1] == 3 and D[n] == 3)
	{
		cout << "YES" << endl;

		return 0;
	}

	if(D[1] >= 3 or D[n] > 3)
	{
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;
	
	return (0-0);	
}