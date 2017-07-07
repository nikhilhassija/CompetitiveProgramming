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
	int n;
	cin >> n;

	vector <pii> A(n), B(n);
	for(int i=0; i<n; i++)
		cin >> A[i].first;

	for(int i=0; i<n; i++)
		cin >> B[i].first;

	for(int i=0; i<n; i++)
		A[i].second = B[i].second = i;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int a = A[0].first + B[0].first + (1e8 * (A[0].second == B[0].second));
	int b = A[0].first + B[1].first + (1e8 * (A[0].second == B[1].second));
	int c = A[1].first + B[0].first + (1e8 * (A[1].second == B[0].second));
	int d = A[1].first + B[1].first + (1e8 * (A[1].second == B[1].second));

	cout << min(min(a, b), min(c, d)) << endl;

	return (0-0);	
}