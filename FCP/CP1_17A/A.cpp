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

vector <int> A;

int check(int, int);

int main()
{
	int n, mc;
	cin >> n >> mc;

	A.resize(n);
	for(int i=0; i<n; i++)
		cin >> A[i];

	int mx = 0;
	for(int i=0; i<n; i++)
		mx = max(mx, A[i]);

	int l = 1;
	int h = mx + 1;
	int a = h;

	while(l <= h)
	{
		int m = (l + h) / 2;

		if(check(m, mc))
		{
			h = m - 1;
			a = min(m, a);
		}
		else
			l = m + 1;
	}

	cout << a << endl;

	return (0-0);	
}

int check(int a, int b)
{
	int s = 0;
	for(int i=0; i<A.size(); i++)
		s += (A[i] / a) + (A[i] % a != 0);

	return (s <= b);
}