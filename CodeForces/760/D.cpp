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

lli get90(lli);

int main()
{
	int n;
	cin >> n;

	lli T[n];
	for(int i=0; i<n; i++)
		cin >> T[i];

	// for(int i=1; i<n; i++)
		// T[i] += T[i-1];

	lli B[n];
	B[0] = 20ll;

	for(int i=1; i<n; i++)
	{
		lli x, y, z;
		x = B[i-1] + 20;

		y = 50 * get90(T[i]);

		z = (120 * (T[i] / 1440));
		lli t = T[i] % 1440;
		z +=  min(50 * get90(t), 120ll);

		B[i] = min(x, min(y, z));
	}

	cout << B[0] << endl;
	for(int i=1; i<n; i++)
		cout << (B[i] - B[i-1]) << endl;
}

lli get90(lli t)
{
	return (t / 90) + (t % 90 != 0);
}