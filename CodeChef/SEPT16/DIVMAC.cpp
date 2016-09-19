#include <bits/stdc++.h>

using namespace std;

struct node 
{
	int offset;
	int L[20];
};

node T[400005];
int A[100005];
vector <int> P;

void init();
void assign(int *, int);
void segtree_build(int, int, int);
int segtree_query(int, int, int, int, int);
void segtree_update(int, int, int, int, int);

int main()
{
	ios_base::sync_with_stdio(false);

	init();

	int t;
	cin >> t;

	while(t--)
	{
		int n,m;
		cin >> n >> m;

		for(int i=0;i<n;i++)
			cin >> A[i];

		segtree_build(1, 0, n-1);

		while(m--)
		{
			int q,l,r;
			cin >> q >> l >> r;

			l--;
			r--;

			if(q)
				cout << segtree_query(1, 0, n-1, l, r) << " ";
			else
				segtree_update(1, 0, n-1, l, r);
		}
		cout << '\n';
	}
}

void init()
{
	int n = 1e6 + 5;
	int L[n];
	memset(L,0,sizeof(L));

	for(int i=2;i<n;i++)
	{
		if(L[i] == 0)
		{
			L[i] = i;
			P.push_back(i);
		}

		for(int j=0;j<P.size() && P[j] <= L[i] && i*P[j] < n;j++)
			L[i*P[j]] = P[j];
	}
}

void assign(int * L, int x)
{
	int k = 0;
	int p = 0;

	while(x > 1)
	{
		while(x % P[p] == 0)
		{
			L[k] = P[p];
			x /= P[p];
			k++;
		}
		p++;
	}

	L[k] = 1;
}

void segtree_build(int node, int l, int r)
{
	if(l == r)
	{
		T[node].offset = 0;
		assign(T[node].L,A[l]);
		return ;
	}

	int m = (l+r)/2;
	int lnode = 2*node;
	int rnode = 2*node + 1;

	segtree_build(lnode, l, m);
	segtree_build(rnode, m+1, r);

	T[node].offset = 0;

	T[node].L[0] = max(T[lnode].L[0],T[rnode].L[0]);

	for(int i=1;i<20 && T[node].L[i-1] > 1;i++)
		T[node].L[i] = max(T[lnode].L[i],T[rnode].L[i]);
}

int segtree_query(int node, int l, int r, int ql, int qr)
{
	if(qr < l || r < ql)
		return 0;

	if(T[node].L[T[node].offset] == 1)
		return 1;

	if(ql <= l && r <= qr)
		return T[node].L[T[node].offset];

	int lnode = 2*node;
	int rnode = 2*node + 1;
	if(T[node].offset)
	{
		for(int i=0;i<T[node].offset && T[lnode].L[T[lnode].offset] > 1;i++,T[lnode].offset++);
		
		for(int i=0;i<T[node].offset && T[rnode].L[T[rnode].offset] > 1;i++,T[rnode].offset++);

		T[node].offset = 0;

		int loff = T[lnode].offset;
		int roff = T[rnode].offset;
		int i=0;
		for(;i<20 && T[lnode].L[loff+i] > 1 && T[rnode].L[roff+i] > 1;i++)
			T[node].L[i] = max(T[lnode].L[loff+i],T[rnode].L[roff+i]);

		while(i < 20 && T[lnode].L[loff+i] > 1)
		{
			T[node].L[i] = T[lnode].L[loff + i];
			i++;
		}

		while(i < 20 && T[rnode].L[roff+i] > 1)
		{
			T[node].L[i] = T[rnode].L[roff + 1];
			i++;
		}

		T[node].L[i] = 1;


	}
	int m = (l+r)/2;

	return max(
		segtree_query(lnode, l, m, ql, qr),
		segtree_query(rnode, m+1, r, ql, qr)
		);
}

void segtree_update(int node, int l, int r, int ul, int ur)
{
	if(ur < l || r < ul)
		return ;

	if(T[node].L[T[node].offset] == 1)
		return ;

	if(ul <= l && r <= ur)
	{
		T[node].offset++;
		return ;
	}

	int lnode = 2*node;
	int rnode = 2*node + 1;
	if(T[node].offset)
	{
		for(int i=0;i<T[node].offset && T[lnode].L[T[lnode].offset] > 1;i++,T[lnode].offset++);
		
		for(int i=0;i<T[node].offset && T[rnode].L[T[rnode].offset] > 1;i++,T[rnode].offset++);

		T[node].offset = 0;

		int loff = T[lnode].offset;
		int roff = T[rnode].offset;
		int i=0;
		for(;i<20 && T[lnode].L[loff+i] > 1 && T[rnode].L[roff+i] > 1;i++)
			T[node].L[i] = max(T[lnode].L[loff+i],T[rnode].L[roff+i]);

		while(i < 20 && T[lnode].L[loff+i] > 1)
		{
			T[node].L[i] = T[lnode].L[loff + i];
			i++;
		}

		while(i < 20 && T[rnode].L[roff+i] > 1)
		{
			T[node].L[i] = T[rnode].L[roff + 1];
			i++;
		}

		T[node].L[i] = 1;
	}	

	int m = (l+r)/2;

	segtree_update(lnode, l, m, ul, ur);
	segtree_update(rnode, m+1, r, ul, ur);

	int loff = T[lnode].offset;
	int roff = T[rnode].offset;
	int i=0;
	for(;i<20 && T[lnode].L[loff+i] > 1 && T[rnode].L[roff+i] > 1;i++)
		T[node].L[i] = max(T[lnode].L[loff+i],T[rnode].L[roff+i]);

	while(i < 20 && T[lnode].L[loff+i] > 1)
	{
		T[node].L[i] = T[lnode].L[loff + i];
		i++;
	}

	while(i < 20 && T[rnode].L[roff+i] > 1)
	{
		T[node].L[i] = T[rnode].L[roff + 1];
		i++;
	}

	T[node].L[i] = 1;
}