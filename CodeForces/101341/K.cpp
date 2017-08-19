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

struct interval
{
	int a, b, c, d;
	bool operator<(const interval &t) const {
		return b < t.b;
	}
} A[200005];
int P[200005];
pll ans[200005];
int par[200005];
int main()
{
	int n;
	cin>>n;
	for(int i = 0; i < n; i++)	{
		cin>>A[i].a>>A[i].b>>A[i].c;
		A[i].d = i+1;
	}
	sort(A, A+n);
	for(int i = 0; i < n; i++)	{
		interval s = {0, A[i].a, 0};
		int x = lower_bound(A, A+n, s) - A;
		if(A[x].b > A[i].a)
			x--;
		P[i] = x;
		//cout<<x<<' ';
	}
	//cout<<endl;
	bool inc[200005] = {};
	for(int i = 0; i < n; i++)	{
		pll wi = {A[i].c, A[i].b - A[i].a};
		if(P[i] != -1)
			wi._F += ans[P[i]]._F,
			wi._S += ans[P[i]]._S;
		pll wo = (i > 0)?ans[i-1]:make_pair(0LL, 0LL);
		if(wi._F > wo._F || (wi._F == wo._F and wi._S < wo._S))	{
			par[i] = P[i];
			ans[i] = wi;
			inc[i] = 1;
		}
		else	{
			par[i] = i-1;
			ans[i] = wo;
			inc[i] = 0;
		}
		assert(ans[i]._F >= 0);

	}
	int start = n-1;
	lli use, dur;
	use = ans[n-1]._F, dur = ans[n-1]._S;
	int k = 0;
	vector<int> ind;
	while(start >= 0)	{
		if(inc[start])	{
			ind.push_back(A[start].d);
			k++;
			start = par[start];
		}
		else
			start--;
	}
	cout<<k<<' '<<use<<' '<<dur<<'\n';
	for(int i = ind.size() - 1; i >= 0; i--)
		cout<<ind[i]<<' ';
	cout<<endl;


	
	return (0-0);	
}