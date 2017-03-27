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

	set <int> S, T;

	for(int i=0; i<m; i++)
	{
		S.clear();
		T.clear();

		int k;
		cin >> k;

		for(int j=0; j<k; j++)
		{
			int x;
			cin >> x;

			S.insert(x);
			T.insert(abs(x));
		}

		if(S.size() == T.size())
		{
			cout << "YES" << endl;
			return 0;
		}
	}

	cout << "NO" << endl;

	return (0-0);	
}