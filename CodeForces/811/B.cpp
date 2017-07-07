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
	fastio();

	int n, m;
	cin >> n >> m;

	int A[n+1];
	for(int i=1; i<=n; i++)
		cin >> A[i];

	while(m--)
	{
		int l, r, x;
		cin >> l >> r >> x;

		int c = 0;

		for(int i=l; i<=r; i++)
			if(A[i] < A[x])
				c++;

		if(c == (x - l))
			cout << "Yes" << endl;
		else 
			cout << "No" << endl;
	}	

	return (0-0);	
}