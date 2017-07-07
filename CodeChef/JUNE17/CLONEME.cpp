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
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;
		
		int q;
		cin >> q;

		vector <int> A(n);
		for(int i=0; i<n; i++)
			cin >> A[i];


		while(q--)
		{
			int a, b, c, d;
			cin >> a >> b;
			cin >> c >> d;

			a--; c--;

			vector <int> l(A.begin()+a, A.begin() + b);
			vector <int> r(A.begin()+c, A.begin() + d);

			sort(l.begin(), l.end());
			sort(r.begin(), r.end());

			int x = 0;
			for(int i=0; i<r.size(); i++)
				x += (l[i] != r[i]);

			if(x < 2)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}		
	}

	return (0-0);	
}