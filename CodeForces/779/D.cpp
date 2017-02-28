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
	string t, p;
	cin >> t >> p;

	int n = t.size();
	int P[n];
	for(int i=0; i<n; i++)
		cin >> P[i];

	vector < pair <int, char> > A(n);
	for(int i=0; i<n; i++)
		A[i] = {-P[i], t[i]};

	reverse(p.begin(), p.end());

	int j=0;
	for(int i=0; i<n; i++)
	{
		if(A[i].second == p[j])
			j++;
		if(j == p.size())
		{
			cout << (n-1) - i << endl;
			return 0;
		}
	}

	return (0-0);	
}