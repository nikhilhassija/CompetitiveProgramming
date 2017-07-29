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
	cin >> n >> m;

	int d = min(n, m);

	cout << d + 1 << endl;
	for(int i = 0; i <= d; i++)
		cout << i << " " << (d - i) << endl;
	
	return (0-0);	
}