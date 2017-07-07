#include <bits/stdc++.h>

#define lli long double
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))
#define fastio() ios_base::sync_with_stdio(0)

using namespace std;

struct node
{
	lli max_pre;
	lli max_suf;
	lli max_sum;
	lli tot_sum;
};

const int MAX_N = 1e5 + 5;
const lli inf   = 1e16;

lli  A[MAX_N]; 
node T[MAX_N * 4];

void build(int, int, int);
node query(int, int, int, int, int);
void update(int, int, int, int, lli);

int main()
{
	fastio();

	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		for(int i=0; i<n; i++)
			cin >> A[i];

		build(1, 0, n-1);

		for(int i=0; i<n; i++)
		{
			int x; 
			cin >> x;
			x--;

			update(1, 0, n-1, x, -inf);

			auto N = query(1, 0, n-1, 0, n-1);

			lli ans = max(
				max(N.max_pre, N.max_suf), 
				max(N.max_sum, N.tot_sum));

			lli z = 0;

			cout << (long long int)max(z, ans) << endl;
		}
	}

	return (0-0);	
}

void build(int node, int tl, int tr)
{
	if(tl == tr)
	{
		T[node].max_pre = A[tl];
		T[node].max_suf = A[tl];

		T[node].max_sum = A[tl];
		T[node].tot_sum = A[tl];
		
		return ;
	}

	int tm = (tl + tr) / 2;

	int lc = 2*node;
	int rc = lc + 1;

	build(lc, tl, tm);
	build(rc, tm + 1, tr);

	T[node].max_pre = max(
		max(T[lc].max_pre, T[lc].tot_sum + T[rc].max_pre), 
		max(T[lc].tot_sum, T[lc].tot_sum + T[rc].tot_sum));

	T[node].max_suf = max(
		max(T[rc].max_suf, T[rc].tot_sum + T[lc].max_suf), 
		max(T[rc].tot_sum, T[rc].tot_sum + T[lc].tot_sum));

	T[node].max_sum = max(
		T[lc].max_suf + T[rc].max_pre,
		max(T[lc].max_sum, T[rc].max_sum));

	T[node].tot_sum = T[lc].tot_sum + T[rc].tot_sum;
}

node query(int node, int tl, int tr, int ql, int qr)
{
	if(ql <= tl and tr <= qr)
		return T[node];

	int tm = (tl + tr) / 2;
	int lc = 2 * node;
	int rc = lc + 1;

	if(qr <= tm)
		return query(lc, tl, tm, ql, qr);
	
	if(tm < ql)
		return query(rc, tm + 1, tr, ql, qr);

	auto ln = query(lc, tl, tm, ql, qr);
	auto rn = query(rc, tm+1, tr, ql, qr);

	return {
		max(max(ln.max_pre, ln.tot_sum + rn.max_pre), 
			max(ln.tot_sum, ln.tot_sum + rn.tot_sum)),
		max(max(rn.max_suf, rn.tot_sum + ln.max_suf),
			max(rn.tot_sum, rn.tot_sum + ln.tot_sum)),
		max(ln.max_suf + rn.max_pre,
			max(ln.max_sum, rn.max_sum)),
		ln.tot_sum + rn.tot_sum
	};
}

void update(int node, int tl, int tr, int x, lli v)
{
	if(tl == tr)
	{
		if(tl == x)
		{
			T[node].max_pre = v;
			T[node].max_suf = v;

			T[node].max_sum = v;
			T[node].tot_sum = v;
		}

		return ;
	}

	int tm = (tl + tr) / 2;
	int lc = 2 * node;
	int rc = lc + 1;

	if(x <= tm)
		update(lc, tl, tm, x, v);
	else
		update(rc, tm+1, tr, x, v);

	T[node].max_pre = max(
		max(T[lc].max_pre, T[lc].tot_sum + T[rc].max_pre), 
		max(T[lc].tot_sum, T[lc].tot_sum + T[rc].tot_sum));

	T[node].max_suf = max(
		max(T[rc].max_suf, T[rc].tot_sum + T[lc].max_suf), 
		max(T[rc].tot_sum, T[rc].tot_sum + T[lc].tot_sum));

	T[node].max_sum = max(
		T[lc].max_suf + T[rc].max_pre,
		max(T[lc].max_sum, T[rc].max_sum));

	T[node].tot_sum = T[lc].tot_sum + T[rc].tot_sum;	
}