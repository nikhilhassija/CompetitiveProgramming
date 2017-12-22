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
	int t;
	cin >> t;

	while (t--)
	{
		lli n, k;
		cin >> n >> k;

		lli A[n];
		for (int i = 0; i < n; i++)
			cin >> A[i];

		stack <lli> S;

		lli ans = 0;
		lli i   = 0;

		while (i < n)
		{
			if (S.empty() or A[S.top()] <= A[i])
				S.push(i++);
			else
			{
				auto h = A[S.top()];
				S.pop();

				if (S.empty())
					ans = max(ans, h * i);
				else
					ans = max(ans, h * (i - S.top() - 1));
			}
		}

		while (not S.empty())
		{
			auto h = A[S.top()];
			S.pop();

			if (S.empty())
				ans = max(ans, h * i);
			else
				ans = max(ans, h * (i - S.top() - 1));	
		}

		cout << ans << endl;
	}
	
	return (0-0);	
}