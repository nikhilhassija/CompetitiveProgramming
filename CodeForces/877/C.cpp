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

	int moves = n + n / 2;

	cout << moves << endl;

	for (int i = 2; i <= n; i += 2)
		cout << i << " ";

	for (int i = 1; i <= n; i += 2)
		cout << i << " ";

	for (int i = 2; i <= n; i += 2)
		cout << i << " ";
	
	cout << endl;

	return (0-0);	
}