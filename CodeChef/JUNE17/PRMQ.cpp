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

int P[MAX_N];
int A[MAX_N];
vector <vector <int> > F(MAX_N);
vector <vector <int> > T;

void sieve();

void build(int, int, int);
int query(int, int, int, int, int, int, int);

int main()
{
	sieve();

	int n;
	cin >> n;

	T.resize(4*n);

	for(int i=0; i<n; i++)
		cin >> A[i];

	build(1, 0, n-1);

	int q;
	cin >> q;

	while(q--)
	{
		int l, r, x, y;
		cin >> l >> r >> x >> y;

		int ans = query(1, 0, n-1, l-1, r-1, x, y);

		cout << ans << endl;
	}

	return (0-0);	
}

void sieve()
{
	mset(P);
	P[1] = 1;

	for(int i=2; i<MAX_N; i++)
	{
		if(not P[i])
		{
			P[i] = i;

			for(int j=2*i; j<MAX_N; j+=i)
			{
				if(not P[j])
					P[j] = i;
			}
		}
	}

	for(int i=2; i<MAX_N; i++)
	{
		int x = i;
		while(x != 1)
		{
			F[i].pb(P[x]);

			x /= P[x];
		}
	}
}

void build(int node, int l, int r)
{
	if(l == r)
	{
		T[node].insert(T[node].end(), 
			F[A[l]].begin(), F[A[l]].end());

		return ;
	}

	int m = (l + r) / 2;
	int lc = 2 * node;
	int rc = lc + 1;

	build(lc, l, m);
	build(rc, m+1, r);

	T[node].insert(T[node].end(),
		T[lc].begin(), T[lc].end());

	T[node].insert(T[node].end(),
		T[rc].begin(), T[rc].end());

	sort(T[node].begin(), T[node].end());
}

int query(int node, int tl, int tr, 
	int ql, int qr, int pl, int pr)
{
	if(tr < ql or qr < tl)
		return 0;

	if(ql <= tl and tr <= qr)
	{
		int ans = upper_bound(
			T[node].begin(), T[node].end(), pr)
		- lower_bound(
			T[node].begin(), T[node].end(), pl);

		return ans;
	}

	int tm = (tl + tr) / 2;
	int lc = 2 * node;
	int rc = lc + 1;

	int la = query(lc, tl, tm, ql, qr, pl, pr);
	int ra = query(rc, tm+1, tr, ql, qr, pl, pr);

	return la + ra;
}