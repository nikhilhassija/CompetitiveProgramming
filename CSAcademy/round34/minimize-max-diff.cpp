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

const int MAX_N = 1e5 + 5;

lli D[MAX_N];

lli T[4 * MAX_N];

void build(int, int, int);
lli query(int, int, int, int, int);

int main()
{
	int n, k;
	cin >> n >> k;

	lli A[n];
	for(int i=0; i<n; i++)
		cin >> A[i];

	for(int i=0; i<n-1; i++)
		D[i] = A[i+1] - A[i];

	build(1, 0, n-2);

	lli ans = 2e10;

	for(int l=k, r=0; l>=0; l--, r++)
	{
		ans = min(ans, query(1, 0, n-2, l, n-2-r));
	}

	cout << ans << endl;

	return (0-0);	
}

void build(int node, int l, int r)
{
	if(l == r)
	{
		T[node] = D[l];
		return ;
	}

	int m = (l + r) / 2;
	int lc = 2 * node;
	int rc = lc + 1;

	build(lc, l, m);
	build(rc, m+1, r);

	T[node] = max(T[lc], T[rc]);
}

lli query(int node, int tl, int tr, int ql, int qr)
{
	if(qr < tl or tr < ql)
		return 0;

	if(ql <= tl and tr <= qr)
		return T[node];

	int tm = (tl + tr) / 2;
	int lc = 2 * node;
	int rc = lc + 1;

	return max(
		query(lc, tl, tm, ql, qr),
		query(rc, tm+1, tr, ql, qr));
}