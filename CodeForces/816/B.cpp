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

const int MAX_N = 200005;

int main()
{
	int n, k, q;
	cin >> n >> k >> q;

	int A[MAX_N], R[MAX_N];
	mset(A);
	mset(R);

	while(n--)
	{
		int l, r;
		cin >> l >> r;

		R[l]++;
		R[r+1]--;
	}

	int r = 0;
	for(int i=0; i<MAX_N; i++)
	{
		r += R[i];
		A[i] = r;
	}

	int P[MAX_N];
	mset(P);
	for(int i=1; i<MAX_N; i++)
		P[i] = P[i-1] + (A[i] >= k);

	while(q--)
	{
		int l, r;
		cin >> l >> r;

		int ans = P[r] - P[l-1];
		cout << ans << endl;
	}

	return (0-0);	
}