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
	lli n, k;
	cin >> n >> k;

	lli t = n / k;

	if(t % 2)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	
	return (0-0);	
}