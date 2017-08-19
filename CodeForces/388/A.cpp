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

	int X[n];
	for(int i = 0; i < n; i++)
		cin >> X[i];

	vector < vector <int> > A(101);
	for(int i = 0; i < A.size(); i++)
		A[i].clear();

	sort(X, X + n);

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= 100; j++)
		{
			if(A[j].size() <= X[i])
			{
				A[j].pb(X[i]);
				break;
			}
		}
	}

	int ans = 0;
	for(int i = 0; i <= 100; i++)
		ans += (A[i].size() != 0);

	cout << ans << endl;
	
	return (0-0);	
}