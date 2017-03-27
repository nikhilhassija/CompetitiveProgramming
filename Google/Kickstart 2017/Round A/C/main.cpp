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

struct sphere
{
	int x, y, z;
	int r;
};

struct point
{
	int x, y, z;
};

vector <sphere> A;
vector <int> B;

int fits(int);
void fit(point *, sphere);
int between(point, sphere, point);

const int inf = 1e9; 

int main()
{
	int _t;
	cin >> _t;

	for(int t=1; t<=_t; t++)
	{
		int n;
		cin >> n;

		A.clear();

		while(n--)
		{
			int x, y, z, r;
			cin >> x >> y >> z >> r;

			A.push_back({x, y, z, r});
		}

		int l = 1;
		int r = inf;

		int ans = inf;

		while(l < r)
		{
			int m = (l + r) / 2;

			if(fits(m))
			{
				ans = min(ans, m);
				r = m;
			}
			else
				l = m + 1;
		}

		printf("Case #%d: %d\n", t, ans);
	}

	return (0-0);	
}

int fits(int l)
{
	B.clear();
	B.resize(A.size(), 0);

	point a = {inf, inf, inf};

	for(int i=0; i<A.size(); i++)
		fit(&a, A[i]);

	point b = {a.x + l, a.y + l, a.z + l};

	for(int i=0; i<A.size(); i++)
	{
		if(between(a, A[i], b))
			B[i] = 1;
	}

	a = {inf, inf, inf};

	for(int i=0; i<A.size(); i++)
		if(!B[i])
			fit(&a, A[i]);

	b = {a.x + l, a.y + l, a.z + l};

	for(int i=0; i<A.size(); i++)
	{
		if(between(a, A[i], b))
			B[i] = 1;
	}

	int n = 0;
	for(int i=0; i<A.size(); i++)
		if(B[i])
			n++;

	return (n == A.size());
}

int between(point l, sphere s, point r)
{
	int f = 0;

	if((l.x <= (s.x - s.r)) and ((s.x + s.r) <= r.x))
		f++;

	if((l.y <= (s.y - s.r)) and ((s.y + s.r) <= r.y))
		f++;

	if((l.z <= (s.z - s.r)) and ((s.z + s.r) <= r.z))
		f++;

	return (f == 3);
}

void fit(point *m, sphere s)
{
	m->x = min(m->x, s.x - s.r);
	m->y = min(m->y, s.y - s.r);
	m->z = min(m->z, s.z - s.r);
}