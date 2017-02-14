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
	string a, b;
	cin >> a >> b;

	if(a == b)
		cout << -1 << endl;
	else if(a.size() > b.size())
		cout << a.size() << endl;
	else
		cout << b.size() << endl;
}