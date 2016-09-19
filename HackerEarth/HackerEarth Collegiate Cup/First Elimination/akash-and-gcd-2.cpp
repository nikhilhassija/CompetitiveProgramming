#include <bits/stdc++.h>

#define lli long long int
#define pll pair <lli,lli>

using namespace std;

const lli MOD = 1e9 + 7;
lli F[500010];
lli A[1000005];
lli T[4000006];
vector < vector <lli> > Factors(500010);

void init();
void segtree_build(lli, lli, lli);
lli segtree_query(lli, lli, lli, lli, lli);
void segtree_update(lli, lli, lli, lli, lli);
lli func(lli x, int p=0);
pll frac(pll, pll);
lli mul(lli, lli);

int main()
{
	ios_base::sync_with_stdio(false);

	init();

	lli n;
	cin >> n;

	for(lli i=0;i<n;i++)
		cin >> A[i];

	segtree_build(1,0,n);

	lli q;
	cin >> q;

	while(q--)
	{
		char c;
		lli x,y;

		cin >> c >> x >> y;

		if(c == 'C')
			cout << segtree_query(1, 0, n, x-1, y-1) << '\n';
		else
			segtree_update(1, 0, n, x-1, y);
	}
}


void init()
{
	for(lli i=1;i<500010;i++)
	{
		for(lli j=1;j<sqrt(i);j++)
		{
			if(i % j == 0)
			{
				Factors[i].push_back(j);
				Factors[i].push_back(i/j);
			}

			lli sq = sqrt(i);
			if(sq * sq == i)
				Factors[i].push_back(sq);
		}

		sort(Factors[i].begin(), Factors[i].end());

		// F[i] = func(i);	
	}
}

void segtree_build(lli node, lli l, lli r)
{
	if(l == r)
	{
		T[node] = func(A[l]);
	}
	else
	{
		lli m = (l+r)/2;

		lli lnode = 2*node;
		lli rnode = lnode + 1;
		
		segtree_build(lnode, l, m);
		segtree_build(rnode, m+1, r);

		T[node] = (T[lnode] + T[rnode]) % MOD;
	}
}

lli segtree_query(lli node, lli l, lli r, lli ql, lli qr)
{
	if(qr < l || r < ql)
		return 0;

	if(ql <= l && r <= qr)
		return T[node];

	lli m = (l+r)/2;

	return (segtree_query(2*node, l, m, ql, qr) + segtree_query(2*node + 1, m+1, r, ql, qr)) % MOD;
}

void segtree_update(lli node, lli l, lli r, lli x, lli val)
{
	if(l == r)
	{
		A[x] = val;
		T[node] = func(A[x]);
	}	
	else
	{
		lli m = (l+r)/2;

		if(x <= m)
			segtree_update(2*node, l, m, x, val);
		else
			segtree_update(2*node + 1, m+1, r, x, val);

		T[node] = (T[2*node] + T[2*node + 1]) % MOD;	
	}
}

lli func(lli x, int p)
{
	lli ans = (x*(x+1))/2;

	map <lli, pll> M;


	for(int i=0;i<Factors[x].size();i++)
	{
		pll f = make_pair(1,1);

		for(lli j=2;j<sqrt(Factors[x][i]);j++)
		{
			if(Factors[x][i] % j == 0)
			{
				f = frac(f,M[j]);
				f = frac(f,M[Factors[x][i]/j]);
			}
		}

		lli sqr = sqrt(Factors[x][i]);
		if(Factors[x][i] > 1 && sqr * sqr == Factors[x][i])
		{
			f = frac(f,M[sqrt(Factors[x][i])]);
		}

		// for(int j=0;j<U.size();j++)
			// if(Factors[x][i] % U[j].first == 0)
				// f = frac(f,U[j].second);

		lli sum = mul(Factors[x][i],x);

		f = frac(f,make_pair(1,Factors[x][i]));
		sum = (sum*f.first)/f.second;

		// U.push_back(make_pair(Factors[x][i],f));
		M[Factors[x][i]] = f;

		ans -= sum;
	}

	return ans % MOD;
}

pll frac(pll a, pll b)
{
	pll ans;
	ans.first = a.first*b.second - a.second*b.first;
	ans.second = a.second*b.second;

	lli g = __gcd(abs(ans.first), ans.second);

	ans.first /= g;
	ans.second /= g;

	return ans;
}

lli mul(lli a, lli b)
{
    lli temp = b/a;
    return a*temp*(temp+1)/2;
}