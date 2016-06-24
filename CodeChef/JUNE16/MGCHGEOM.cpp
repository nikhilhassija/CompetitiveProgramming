#include <bits/stdc++.h>

using namespace std;

struct point {
	long long int x, y;

	bool operator <(const point &p) const 
	{
		return x < p.x || (x == p.x && y < p.y);
	}

	bool operator == (const point &p) const 
	{
		return x == p.x && y == p.y;
	}
};

const long long int MAX_N = 1e5 + 5;

vector <point> P;
vector <point> H;
multiset <point> S;

long long int cross(point, point, point);
int convex_hull();
long double area(point, point, point);

int main()
{
	int t;
	cin>>t;

	H.resize(2*MAX_N);

	while(t--)
	{
		int n;
		cin>>n;

		S.clear();
		int sz = 0;
		long double a = 0;

		while(n--)
		{
			char c;
			point p;
			cin>>c>>p.x>>p.y;

			int f = 0;
			if(c == '+')
			{
				S.insert(p);

				long double temp = 0;
				for(int i=0;i<sz-1;i++)
					temp += area(p,H[i],H[i+1]);

				if(temp != a || a == 0.0)
				{
					f = 1;
					P.assign(S.begin(),S.end());
					sz = convex_hull();
				}
			}

			if(c == '-')
			{
				auto it = S.find(p);
				S.erase(p);

				for(int i=0;i<sz;i++)
				{
					if(H[i] == p)
					{
						f = 1;
						break;
					}
				}

				if(f)
				{
					P.assign(S.begin(),S.end());
					sz = convex_hull();
				}	
			}

			if(f)
			{
				a = 0;
				for(int i=1;i<sz-1;i++)
					a += area(H[0],H[i],H[i+1]);
			}

			printf("%.1Lf\n",a);
		}
	}
}

long long int cross(point O, point A, point B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

int convex_hull()
{
	int n = P.size(), k = 0;

	sort(P.begin(), P.end());

	for (int i = 0; i < n; ++i) 
	{
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) >= 0)
			k--;

		H[k++] = P[i];
	}

	for (int i = n-2, t = k+1; i >= 0; i--) 
	{
		while (k >= t && cross(H[k-2], H[k-1], P[i]) >= 0)
			k--;

		H[k++] = P[i];
	}

	return k - 1;
}

long double area(point a, point b, point c)
{
	long double ans = 0;
	ans += a.x*(b.y - c.y);
	ans += b.x*(c.y - a.y);
	ans += c.x*(a.y - b.y);

	if(ans < 0)
		ans = -ans;

	return ans/2;
}
