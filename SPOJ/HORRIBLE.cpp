#include <bits/stdc++.h>

#define lli long long int
#define mset(x) memset(x, 0, sizeof(x))
#define left(x) (2 * x)
#define right(x) (2* x + 1)

using namespace std;

const int MAX_N = 1e5;

lli T[4 * MAX_N];
lli L[4 * MAX_N];

void update (lli, lli, lli, lli, lli , lli);
lli  query  (lli, lli, lli, lli, lli);

void print(int);

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		mset(T);
		mset(L);

		int n, c;
		cin >> n >> c;

		while(c--)
		{
			int x, p, q, v;
			cin >> x;

			if(not x)
			{
				cin >> p >> q >> v;

				update(1, 0, n-1, p-1, q-1, v);
			}
			else
			{
				cin >> p >> q;

				cout << query(1, 0, n-1, p-1, q-1) << endl;
			}

			// print(n);
		}
	}

	return (0-0);	
}

void update(lli node, lli tl, lli tr, lli ql, lli qr, lli v)
{
	if(L[node])
	{
		T[node] += (tr - tl + 1) * L[node];

		if(tl != tr)
		{
			L[left(node)]  += L[node];
			L[right(node)] += L[node];
		}

		L[node] = 0;
	}

	if(tl > tr or qr < tl or tr < ql)
		return;

	if(tl >= ql and tr <= qr)
	{
		T[node] += (tr - tl + 1) * v;

		if(tl != tr)
		{
			L[left(node)]  += v;
			L[right(node)] += v;
		}

		return ;
	}

	lli mid = (tl + tr) / 2;

	update(left(node), tl, mid, ql, qr, v);
	update(right(node), mid + 1, tr, ql, qr, v);

	T[node] = T[left(node)] + T[right(node)];
}

lli query(lli node, lli tl, lli tr, lli ql, lli qr)
{
	if(L[node])
	{
		T[node] += (tr - tl + 1) * L[node];

		if(tl != tr)
		{
			L[left(node)]  += L[node];
			L[right(node)] += L[node];
		}

		L[node] = 0;
	}

	if(tl > tr or qr < tl or tr < ql)
		return 0;

	if(tl >= ql and tr <= qr)
		return T[node];

	lli mid = (tl + tr) / 2;

	lli l = query(left(node), tl, mid, ql, qr);
	lli r = query(right(node), mid + 1, tr, ql, qr);

	return (l + r);
}

void print(int n)
{
	for(int i=0; i<n; i++)
		cout << query(1, 0, n-1, i, i) << " ";
	cout << endl;
}