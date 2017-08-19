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

	int x;
	cin >> x;

	int A[n];
	for(int &i: A)
		cin >> i;

	int g = A[0];
	for(auto i: A)
		g = __gcd(g, i);

	if(x % g)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	
	return (0-0);	
}