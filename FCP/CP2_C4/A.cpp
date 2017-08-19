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

const int MAX_N = 2e5 + 5;

vector < vector <int> > L(MAX_N);
vector < vector <int> > R(MAX_N);

int T[100 * MAX_N][3];
int node = 1;

void bin(int *, int);

void trie_insert(int);
void trie_remove(int);

int trie_query(int);

int main()
{
	mset(T);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		int l, r;
		cin >> l >> r;

		L[l].pb(i);
		R[r + 1].pb(i);
	}

	vector <int> Q(n + 1);

	for(int i = 1; i <= n; i++)
	{
		// cerr << "k: " << i << endl;

		// cerr << "inserting: ";

		for(auto j: L[i])
		{
			// cerr << j << " ";
			trie_insert(j);
		}
		// cerr << endl;

		// cerr << "removing: ";

		for(auto j: R[i])
		{
			// cerr << j << " ";
			trie_remove(j);
		}
		// cerr << endl;

		int l = 0;
		int r = n;

		int ans = n + 1;

		while(l <= r)
		{
			int m = (l + r) / 2;
			int q = trie_query(m);

			// cerr << l << " " << r << " -- " << m << " " << q << endl;

			if(q == i)
				ans = min(ans, m);
			
			if(q < i)
				l = m + 1;
			else
				r = m - 1;
		}

		if(ans == n + 1)
			Q[i] = -1;
		else
			Q[i] = ans;
	}

	for(int i = 1; i <= n; i++)
		cout << Q[i] << " ";
	cout << endl;
	
	return (0-0);	
}

void bin(int * A, int k)
{
	for(int i = 31; i >= 0; i--)
	{
		A[i] = k % 2;

		k /= 2;
	}
}

void trie_insert(int x)
{
	int A[32];
	bin(A, x);

	int cur = 1;

	for(int i = 0; i < 32; i++)
	{
		T[cur][2]++;

		if(not T[cur][A[i]])
			T[cur][A[i]] = ++node;

		cur = T[cur][A[i]];
	}

	T[cur][2]++;
}

void trie_remove(int x)
{
	int A[32];
	bin(A, x);

	int cur = 1;

	for(int i = 0; i < 32; i++)
	{
		T[cur][2]--;

		cur = T[cur][A[i]];
	}

	T[cur][2]--;
}

int trie_query(int x)
{
	int A[32];
	bin(A, x);

	int cur = 1;
	int ans = 0;

	for(int i = 0; i < 32; i++)
	{
		if(A[i])
			if(T[cur][0])
				ans += T[T[cur][0]][2];

		if(not T[cur][A[i]])
			return ans;

		cur = T[cur][A[i]];
	}

	return ans;
}