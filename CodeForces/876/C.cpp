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

int sod(int);

int main()
{
	int n;
	cin >> n;

	vector <int> A;

	for (int i = 0; i < 100; i++)
		if ((n - i) + sod((n -i)) == n)
			A.pb(n - i);

	cout << A.size() << endl;

	sort(A.begin(), A.end());

	for (int a: A)
		cout << a << endl;

	return (0-0);	
}

int sod(int x)
{
	int ret = 0;

	while(x)
	{
		ret += x % 10;

		x /= 10;
	}

	return ret;
}