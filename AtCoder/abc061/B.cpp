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
	int n, m;
	cin >> n >> m;

	int D[n+1];
	mset(D);

	while(m--)
	{
		int x, y;
		cin >> x >> y;

		D[x]++;
		D[y]++;
	}

	for(int i=0; i<n; i++)
		cout << D[i+1] << endl;
	
	return (0-0);	
}