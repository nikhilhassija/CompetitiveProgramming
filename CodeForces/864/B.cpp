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

	string A;
	cin >> A;

	set <char> S;

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (isupper(A[i]))
		{
			ans = max(ans, (int) S.size());
			S.clear();
		}
		else
		{
			S.insert(A[i]);
		}
	}

	ans = max(ans, (int) S.size());

	cout << ans << endl;

	return (0-0);	
}