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
	int n, m;
	cin >> m >> n;

	int A[n];
	for (int i = 0; i < n; i++)
		cin >> A[i];
	
	int s = 0;

	int f = m;
	int t = 2 * m;

	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " -- ";
		int a = min(f, A[i] / 4);
		f -= a;

		A[i] -= a * 4;

		int b = min(t, A[i] / 2 + (A[i] % 2));

		if(not s and b)
		{
			if(f)
			{
				f -= b / 2;
			}	
		}

	}

	if(f < 0 or t < 0)
	{
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;

	return (0-0);	
}