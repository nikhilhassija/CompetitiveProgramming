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
	int k;
	cin >> k;

	n %= 6;

	int a[] = {0, 1, 2};

	for(int i=1; i<=n; i++)
	{
		if(i % 2)
			swap(a[0], a[1]);
		else
			swap(a[1], a[2]);
	}

	cout << a[k] << endl;
}