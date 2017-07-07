#include <bits/stdc++.h>

#define lli long long int
#define fastio() ios_base::sync_with_stdio(0)

using namespace std;

const lli MAX_N = 1e6 + 5;

lli A[MAX_N];
lli T[4 * MAX_N];

lli zero(lli);

void build(lli, lli, lli);
lli query(lli, lli, lli, lli);
void update(lli, lli, lli, lli, lli);

int main()
{
	lli n;
	cin >> n;

	for(lli i = 0; i < n; i++)
		cin >> A[i];

	for(lli i = 0; i < n; i++)
		A[i] = zero(A[i]);

	build(1, 0, n-1);

	lli q;
	cin >> q;

	while(q--)
	{
		lli t;
		cin >> t;

		if(t == 1)
		{
			lli k;
			cin >> k;

			cout << query(1, 0, n-1, k) << endl;
		}
		else
		{
			lli i, x;
			cin >> i >> x;

			update(1, 0, n-1, i, zero(x));
		}
	}

	return (0-0);	
}

lli zero(lli x)
{
	lli ans = 0;

	if(x == 0)
		return 1;

	if(x < 0)
		x = -x;

	while(x)
	{
		if(x % 10 == 0)
			ans ++;

		x /= 10;
	}

	return ans;
}

void build(lli node, lli l, lli r)
{
	if(l == r)
	{
		T[node] = A[l];

		return ;
	}

	lli m = (l + r) / 2;

	lli lc = 2 * node;
	lli rc = lc + 1;

	build(lc, l, m);
	build(rc, m + 1, r);

	T[node] = T[lc] + T[rc];
}

void update(lli node, lli l, lli r, lli i, lli x)
{
	if(l == r)
	{
		if(l == i)
			T[node] = x;

		return ;
	}

	lli m = (l + r) / 2;

	lli lc = 2 * node;
	lli rc = lc + 1;

	if(x <= m)
		update(lc, l, m, i, x);
	else
		update(rc, m + 1, r, i, x);

	T[node] = T[lc] + T[rc]; 
}

lli query(lli node, lli l, lli r, lli k)
{
	// prllif("%d %d %d -- %d ? %d\n", node, l, r, T[node], k);

	if(T[node] < k)
		return -1;

	if(l == r)
		return l;

	lli m = (l + r) / 2;

	lli lc = 2 * node;
	lli rc = lc + 1;

	// prllif("%d <= %d\n", k, T[lc]);

	if(k <= T[lc])
	{
		return query(lc, l, m, k);
	}
	else
	{
		return query(rc, m + 1, r, k - T[lc]);
	}
}