#include <bits/stdc++.h>

#define lchild(x) (2 * x)
#define rchild(x) (2 * x + 1)

using namespace std;

vector <int> T, A;
set <int> S;

void build(int, int, int);

void update(int, int, int, int);

int query(int, int, int, int, int);

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		A.resize(n, 0);
		T.resize(4*n);

		for(int i=0; i<n; i++)
			S.insert(i);

		build(1, 0, n-1);

		int last = -1;

		for(int i=1; i<=n; i++)
		{
			int rem = (n - i) + 1;

			int skip = i % rem;

			int idx;

			if(S.upper_bound(last) != S.end())
				idx = *(S.upper_bound(last));
			else
				idx = *(S.begin());			

			while(skip)
			{
				int lo = idx;
				int hi = n-1;

				int num = query(1, 0, n-1, lo, hi);

				if(num <= skip)
				{
					skip -= num;
					idx = *(S.begin());
				}
				else
				{
					while(lo < hi)
					{
						int md = (lo + hi) / 2;

						int num = query(1, 0, n-1, idx, md);

						if(num == skip)
						{
							skip -= num;
							if(S.upper_bound(md) != S.end())
								idx = *(S.upper_bound(md));
							else
								idx = *(S.begin());

							break;
						}
						else if(num < skip)
						{
							skip -= num;
							if(S.upper_bound(md) != S.end())
								idx = *(S.upper_bound(md));
							else
								idx = *(S.begin());
							lo = idx;
						}
						else
						{
							hi = md;
						}
					}
				}
			}

			A[idx] = i;
			last = idx;

			S.erase(idx);

			update(1, 0, n-1, idx);
		}

		for(int i=0; i<n; i++)
			cout << A[i] << " ";
		cout << endl;

		T.clear();
		A.clear();
	}

	return (0-0);	
}

void build(int node, int l, int r)
{
	if(l == r)
	{
		T[node] = 1;
		return ;
	}

	int m= (l + r) / 2;

	build(lchild(node), l, m);
	build(rchild(node), m+1, r);

	T[node] = T[lchild(node)] + T[rchild(node)];
}

void update(int node, int tl, int tr, int x)
{
	if(tl == tr)
	{
		if(tl == x)
			T[node] = 0;
		return ;
	}

	int tm = (tl + tr) / 2;

	if(x <= tm)
		update(lchild(node), tl, tm, x);
	else
		update(rchild(node), tm + 1, tr, x);

	T[node] = T[lchild(node)] + T[rchild(node)];
}

int query(int node, int tl, int tr, int ql, int qr)
{
	if(tr < tl or qr < tl or tr < ql)
		return 0;

	if(ql <= tl and tr <= qr)
		return T[node];

	int tm = (tl + tr) / 2;

	return (query(lchild(node), tl, tm, ql, qr) + 
			query(rchild(node), tm + 1, tr, ql, qr));
}