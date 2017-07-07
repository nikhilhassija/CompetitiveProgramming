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
	int l, r, p;
};

const int MAX_N = 1e4 + 5;
node T[MAX_N];
int root = 0;

void insert(int);
void path(vector <int> &, int);

int main()
{
	int n;
	cin >> n;

	mset(T);

	for(int i=0; i<n; i++)
	{
		int x;
		cin >> x;

		insert(x);
	}

	int a, b;
	cin >> a >> b;

	vector <int> A, B;
	path(A, a);
	path(B, b);

	int k = 0;

	while(k < A.size() and k < B.size() and A[k] == B[k])
		k++;

	int ans = A[k-1];

	for(int i=k; i<A.size(); i++)
		ans += A[i];

	for(int i=k; i<B.size(); i++)
		ans += B[i];

	cout << ans << endl;

	return (0-0);	
}

void insert(int a)
{
	int cur = root;

	while(1)
	{
		if(a < cur)
		{
			if(T[cur].l)
				cur = T[cur].l;
			else
			{
				T[cur].l = a;
				T[a].p = cur;
				return ;
			}
		}
		else
		{
			if(T[cur].r)
				cur = T[cur].r;
			else
			{
				T[cur].r = a;
				T[a].p = cur;
				return ;
			}
		}
	}
}

void path(vector <int> & A, int a)
{
	while(a)
	{
		A.pb(a);
		a = T[a].p;
	}

	reverse(A.begin(), A.end());
}