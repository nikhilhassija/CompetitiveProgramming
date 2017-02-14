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

struct node
{
	int ind, val, rank;
};

bool comp_rank(node, node);
bool comp_ind(node, node);

int main()
{
	int n, l, r;
	cin >> n >> l >> r;

	node A[n];
	for(int i=0; i<n; i++)
		cin >> A[i].val;

	for(int i=0; i<n; i++)
		cin >> A[i].rank;

	for(int i=0; i<n; i++)
		A[i].ind = i;

	sort(A, A+n, comp_rank);

	int B[n];
	int min_val = -(1e9 + 5);

	for(int i=0; i<n; i++)
	{
		int x = A[i].val + min_val + 1;
		x = max(x, l);

		B[A[i].ind] = x;

		min_val = max(min_val, x - A[i].val);
	}

	for(int i=0; i<n; i++)
		if(B[i] > r)
		{
			printf("-1\n");
			return 0;
		}

	for(int i=0; i<n; i++)
		printf("%d ", B[i]);

	printf("\n");
}

bool comp_rank(node a, node b)
{
	return a.rank < b.rank;
}

bool comp_ind(node a, node b)
{
	return a.ind < b.ind;
}