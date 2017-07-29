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

	int A[n];
	for (int i = 0; i < n; i++)
		cin >> A[i];

	const int N = 1e5 + 6;
	lli C[N];
	lli DP[N];
	
	mset(C);
	mset(DP);

	for (int i = 0; i < n; i++)
		C[A[i]]++;

	DP[1] = C[1];

	for(lli i = 2; i < N; i++)
		DP[i] = max(i * C[i] + DP[i - 2], DP[i - 1]);

	cout << DP[N - 1] << endl;
	
	return (0-0);	
}