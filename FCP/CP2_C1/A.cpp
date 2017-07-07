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

const int MAX_N = 1e6 + 5;

int A[MAX_N];

int Tm[4 * MAX_N];
int TM[4 * MAX_N];

void build(int, int, int);
void update(int, int, int, int, int);
pii query(int, int, int, int, int);

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	// cin >> n >> m;

	for(int i=0; i<n; i++)
		scanf("%d", A+i);
		// cin >> A[i];

	build(1, 0, n-1);

	while(m--)
	{
		int t;
		scanf("%d", &t);
		// cin >> t;

		if(t == 1)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			// cin >> x >> y;
			x--;
			y--;

			auto p = query(1, 0, n-1, x, y);
			int ans = p.first - p.second;

			printf("%d\n", ans);
			// cout << ans << endl;
		}

		if(t == 2)
		{
			int i, x;
			scanf("%d %d", &i, &x);
			// cin >> i >> x;

			i--;
			update(1, 0, n-1, i, x);
		}
	}

	return (0-0);	
}

void build(int node, int l, int r)
{
	if(l == r)
	{
		Tm[node] = A[l];
		TM[node] = A[l];

		return ;
	}

	int m = (l + r) / 2;

	int lc = 2 * node;
	int rc = lc + 1;

	build(lc, l, m);
	build(rc, m+1, r);

	Tm[node] = min(Tm[lc], Tm[rc]);
	TM[node] = max(TM[lc], TM[rc]);
}

void update(int node, int l, int r, int x, int v)
{
	if(l == r)
	{
		if(l == x)
		{
			Tm[node] = v;
			TM[node] = v;
		}

		return ;
	}

	int m = (l + r) / 2;

	int lc = 2 * node;
	int rc = lc + 1;

	if(x <= m)
		update(lc, l, m, x, v);
	else
		update(rc, m+1, r, x, v);

	Tm[node] = min(Tm[lc], Tm[rc]);
	TM[node] = max(TM[lc], TM[rc]);
}

pii query(int node, int tl, int tr, int ql, int qr)
{

	if(ql <= tl and tr <= qr)
	{
		return {TM[node], Tm[node]};
	}

	int tm = (tl + tr) / 2;
	int lc = 2 * node;
	int rc = lc + 1;

	if(qr <= tm)
		return query(lc, tl, tm, ql, qr);

	if(ql > tm)
		return query(rc, tm+1, tr, ql, qr);

	auto ln = query(lc, tl, tm, ql, qr);
	auto rn = query(rc, tm+1, tr, ql, qr);

	pii an = {
		max(ln.first, rn.first),
		min(ln.second, rn.second)
	};

	return an;
}