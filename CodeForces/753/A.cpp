#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))
#define fastio() ios_base::sync_with_stdio(0);

using namespace std;

int main()
{
	int n;
	cin >> n;

	int k = 1;
	vector <int> A;
	while(2*k < n)
	{
		A.pb(k);
		n -= k;
		k++;
	}

	A.pb(n);

	cout << k << endl;
	for(int i=0; i<A.size(); i++)
		cout << A[i] << " ";
	cout << endl;
}