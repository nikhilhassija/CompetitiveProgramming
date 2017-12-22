#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))
#define fastio() ios_base::sync_with_stdio(0); cin.tie(NULL)
#define endl "\n"

using namespace std;

vector < int > E, L, R;

vector < vector <int> > C;
vector < int > A;

vector < int > T, X;

void dfs(int node);

void build(int, int, int);
int query(int, int, int, int, int);
void update(int, int, int, int, int);

int main()
{
	fastio();

	int n;
	cin >> n;

	L.resize(n + 1, 0);
	R.resize(n + 1, 0);

	C.resize(n + 1);
	A.resize(n + 1);

	T.resize(4 * n);
	X.resize(4 * n, 0);

	for (int i = 2; i <= n; i++)
	{
		int p;
		cin >> p;

		C[p].pb(i);
	}

	for (int i = 1; i <= n; i++)
		cin >> A[i];

	dfs(1);

	build(1, 0, n - 1);
	
	int q;
	cin >> q;

	while (q--)
	{
		string S;
		cin >> S;

		int x;
		cin >> x;

		if (S == "get")
			cout << query(1, 0, n - 1, L[x], R[x]) << endl;
		else
			update(1, 0, n - 1, L[x], R[x]);			
	}

	return (0-0);	
}

void dfs(int node)
{
	E.pb(node);

	L[node] = E.size() - 1;

	for (int c: C[node])
		dfs(c);

	R[node] = E.size() - 1;
}

void build (int node, int l, int r)
{
	if (l == r)
	{
		T[node] = A[E[l]];
		return ;
	}

	int m = (l + r) / 2;

	int lchild = 2 * node;
	int rchild = lchild + 1;

	build(lchild, l, m);

	build(rchild, m + 1, r);

	T[node] = T[lchild] + T[rchild];
}

void push(int node, int l, int r)
{
	if (X[node])
	{
		T[node] = r + 1 - l - T[node];

		if (l != r)
		{
			X[2 * node] ^= 1;
			X[2 * node + 1] ^= 1; 
		}

		X[node] = 0;

		return;
	}
}

void update (int node, int tl, int tr, int ql, int qr)
{
	push(node, tl, tr);

	if (qr < tl or tr < ql)
		return ;

	if (ql <= tl and tr <= qr)
	{
		X[node] ^= 1;
		push(node, tl, tr);

		return ;
	}

	int tm = (tl + tr) / 2;

	int lchild = 2 * node;
	int rchild = lchild + 1;

	update(lchild, tl, tm, ql, qr);
	update(rchild, tm + 1, tr, ql, qr);

	T[node] = T[lchild] + T[rchild];
}

int query(int node, int tl, int tr, int ql, int qr)
{
	push(node, tl, tr);

	if (qr < tl or tr < ql)
		return 0;

	if (ql <= tl and tr <= qr)
		return T[node];

	int tm = (tl + tr) / 2;

	return query(2 * node, tl, tm, ql, qr) + query(2 * node + 1, tm + 1, tr, ql, qr);
}