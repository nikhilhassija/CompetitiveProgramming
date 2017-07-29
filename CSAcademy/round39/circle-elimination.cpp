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

	vector <pii> A;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		A.pb({x, i});
	}
	
	sort(A.begin(), A.end());

	lli ans = 0;

	for(int i = 0; i < n - 1; i++)
	{
		int x = A[i].second;
		int y = A[i + 1].second;

		if(x > y)
			swap(x, y);

		int d = y - x;

		ans += min(n - d, d);
	}

	cout << ans << endl;

	return (0-0);	
}