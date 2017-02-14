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
	int k, a, b;
	cin >> k >> a >> b;

	if(b > a)
		swap(a, b);

	if((b/k) * (k-1) < a%k)
		cout << -1 << endl;
	else
		cout << a/k + b/k << endl;
}