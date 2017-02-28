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
	int n, k;
	cin >> n >> k;

	lli A[n], B[n];
	for(int i=0; i<n; i++)
		cin >> A[i];

	for(int i=0; i<n; i++)
		cin >> B[i];

	vector < pair <lli, pll> > D(n);
	for(int i=0; i<n; i++)
		D[i] = {A[i] - B[i], {A[i], B[i]}};

	sort(D.begin(), D.end());

	lli ans = 0;

	for(int i=0; i<k; i++)
		ans += D[i].second.first;

	for(int i=k; i<n; i++)
		ans += min(D[i].second.first, D[i].second.second);

	cout << ans << endl;

	return (0-0);	
}