#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))
#define fastio() ios_base::sync_with_stdio(0);

using namespace std;

int main()
{
	int n, m, c;
	cin >> n >> m >> c;

	cout << ((c-1) / (2*m)) + 1 << " ";

	cout << ((c-1) % (2*m)) / 2 + 1 << " ";

	if(c % 2)
		cout << "L";
	else
		cout << "R";

	cout << endl;
}