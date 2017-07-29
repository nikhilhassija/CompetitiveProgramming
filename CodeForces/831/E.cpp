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
const int INF   = 1e6 + 5;

int A[MAX_N];
int P[4 * MAX_N];
int M[4 * MAX_N];

void build(int, int, int);
void update(int, int, int, int);

int search(int, int, int, int, int);
int sum(int, int, int, int, int);

int main()
{
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++)
		cin >> A[i];

	build(1, 0, n - 1);

	multiset <int> S;
	for(int i = 0; i < n; i++)
		S.insert(A[i]);

	lli ans = 0;
	lli cur = 0;

	for(int i = 0; i < n; i++)
	{
		int x = *(S.begin());

		S.erase(S.begin());


		if(search(1, 0, n - 1, cur, n - 1) == x)
		{
			int l = cur;
			int r = n - 1;


			int ind = r;

			while(l <= r)
			{
				int m = (l + r) / 2;

				if(search(1, 0, n - 1, l, m) == x)
				{
					ind = min(ind, m);
					r = m - 1;
				}
				else
				{
					l = m + 1;
				}
			}

			ans += (lli) sum(1, 0, n - 1, cur, ind);


			update(1, 0, n - 1, ind);

			// return 0;

			cur = ind;
		}
		else
		{
			ans += (lli) sum(1, 0, n - 1, cur, n - 1);

			cur = 0;
			S.insert(x);
			i--;
		}
	}

	cout << ans << endl;

	return (0-0);	
}

void build(int node, int l, int r)
{
	if(l == r)
	{
		P[node] = 1;
		M[node] = A[l];

		return ;
	}

	int m = (l + r) / 2;

	int lc = 2 * node;
	int rc = lc + 1;

	build(lc, l, m);
	build(rc, m + 1, r);

	P[node] = P[lc] + P[rc];
	M[node] = min(M[lc], M[rc]);
}

void update(int node, int l, int r, int i)
{
	if(l == r)
	{
		if(l == i)
		{
			P[node] = 0;
			M[node] = INF;
		}

		return ;
	}

	int m = (l + r) / 2;
	int lc = 2 * node;
	int rc = lc + 1;

	if(i <= m)
		update(lc, l, m, i);
	else
		update(rc, m + 1, r, i);

	P[node] = P[lc] + P[rc];
	M[node] = min(M[lc], M[rc]);
}

int search(int node, int tl, int tr, int ql, int qr)
{
	if(qr < tl or tr < ql)
		return INF;

	if(ql <= tl and tr <= qr)
		return M[node];

	int tm = (tl + tr) / 2;
	int lc = 2 * node;
	int rc = lc + 1;

	return min(
		search(lc, tl, tm, ql, qr),
		search(rc, tm + 1, tr, ql, qr));
}

int sum(int node, int tl, int tr, int ql, int qr)
{
	if(qr < tl or tr < ql)
		return 0;

	if(ql <= tl and tr <= qr)
		return P[node];

	int tm = (tl + tr) / 2;
	int lc = 2 * node;
	int rc = lc + 1;

	return sum(lc, tl, tm, ql, qr) + 
			sum(rc, tm + 1, tr, ql, qr);
}
