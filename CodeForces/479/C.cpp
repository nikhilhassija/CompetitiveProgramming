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

int main()
{
	int n;
	cin >> n;

	vector < pii > A(n);

	for (int i = 0; i < n; i++)
		cin >> A[i]._F >> A[i]._S;

	sort(A.begin(), A.end());

	int ans = 0;
	int inf = 1e9 + 10;

	for(int i = 0; i < n; i++)
	{
		int a, b;
		a = b = inf;

		if (ans <= A[i]._F)
			a = A[i]._F;

		if (ans <= A[i]._S)
			b = A[i]._S;

		ans = max(ans, min(a, b));
	}

	cout << ans << endl;

	return (0-0);	
}