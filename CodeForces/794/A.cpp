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
	int a, b, c;
	cin >> a >> b >> c;

	int n;
	cin >> n;

	vector <int> A(n);
	for(int i=0; i<n; i++)
		cin >> A[i];

	sort(A.begin(), A.end());

	int index = lower_bound(A.begin(), A.end(), c) -
		upper_bound(A.begin(), A.end(), b);

	cout << index << endl;
	return (0-0);	
}