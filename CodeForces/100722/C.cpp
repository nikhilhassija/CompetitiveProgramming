#define _USE_MATH_DEFINES

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

int main ()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		double f;
		cin >> n >> f;

		f++;

		double A[n];
		for (int i = 0; i < n; i++)
			cin >> A[i];

		for(int i = 0; i < n; i++)
			A[i] = (A[i] * A[i] * M_PI);

		sort(A, A + n);
		reverse(A, A + n);

		double l = 0;
		double h = A[0];
		double d = 2.0;

		double tol = 1e-5;

		double ans = 0;

		while(abs(h - l) > tol)
		{
			double m = (l + h) / d;

			int cnt = 0;

			for(int i = 0; i < n; i++)
				cnt += floor(A[i] / m);

			if(cnt >= f)
			{
				l = m;
				ans = max(ans, m);
			}
			else
			{
				h = m;
			}
		}

		cout << fixed << setprecision(8) << ans << endl;
	}
	
	return (0-0);	
}