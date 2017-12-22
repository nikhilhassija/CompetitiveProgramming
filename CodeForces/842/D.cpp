#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))
#define fastio() ios_base::sync_with_stdio(0); cin.tie(NULL)

using namespace std;

const int MAX_N = 3e5;
const int BITS  = 20;

int T[MAX_N * BITS][3];
int node = 1;

void bin(int *, int);

void insert(int);

int find(int);

int in_tree(int);

int main()
{
	fastio();

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		if (not in_tree(a))
			insert(a);
	}

	int t = 0;

	while (m--)
	{
		int x;
		cin >> x;

		t ^= x;

		cout << find(t) << endl;
	}
	
	return (0-0);	
}

void bin (int * A, int x)
{
	for (int i = 0; i < BITS; i++)
		A[BITS - 1 - i] = (x >> i) & 1;
}

void insert(int x)
{
	int A[BITS];

	bin(A, x);

	int cur = 1;

	for (int i = 0; i < BITS; i++)
	{
		if (not T[cur][A[i]])
			T[cur][A[i]] = ++node;

		T[cur][2]++;

		cur = T[cur][A[i]];
	}

	T[cur][2]++;
}


int find (int x)
{
	int A[BITS];

	bin (A, x);

	int ans = 0;
	int cur = 1;

	for (int i = 0; i < BITS; i++)
	{
		int go = T[cur][A[i]];

		if (T[go][2] == (1 << (BITS - i - 1)))
		{
			ans = ans * 2 + (A[i] ^ 1);

			cur = T[cur][A[i] ^ 1];
		}
		else
		{
			ans = ans * 2 + (A[i]);

			cur = T[cur][A[i]];
		}
	}

	return ans ^ x;
}

int in_tree(int x)
{
	int A[BITS];

	bin(A, x);

	int cur = 1;

	for (int i = 0; i < BITS; i++)
	{
		if (not T[cur][A[i]])
			return 0;

		cur = T[cur][A[i]];
	}

	return 1;
}