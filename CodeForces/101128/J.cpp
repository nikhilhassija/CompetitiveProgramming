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

double EPS = 1e-12;

struct PT {
	double x, y;
	PT () {}
	
	PT (double x, double y) : x (x) ,y (y) {}

	PT (const PT & p) : x (p.x), y (p.y) {}
	
	PT operator + (const PT &p) const 
	{
		return PT(x + p.x, y + p.y); 
	}
	
	PT operator - (const PT &p) const 
	{ 
		return PT(x - p.x, y - p.y); 
	}
	
	PT operator * (double c) 	const 
	{ 
		return PT (x * c, y * c); 
	}
	PT operator / (double c) const 
	{ 
		return PT (x / c, y / c); 
	}

	bool operator < (const PT &p) const 
	{
		return x < p.x || (x == p.x && y < p.y);
	}
};

vector <PT> hull(vector <PT> &);

bool PointOnPolygon(const vector < PT > &p, PT q); 
bool PointInPolygon(const vector< PT > &p, PT q);

int main()
{
	fastio();

	int L;
	cin >> L;

	vector <PT> A;
	for(int i=0; i<L; i++)
	{
		double x, y;
		cin >> x >> y;

		A.pb({x, y});
	}

	vector <PT> H = hull(A);

	int S;
	cin >> S;

	int ans = 0;

	while(S--)
	{
		double x, y;
		cin >> x >> y;

		PT p = {x, y};

		if(PointOnPolygon(H, p))
			ans++;
		else if(PointInPolygon(H, p))
			ans++;
	}

	cout << ans << endl;

	return (0-0);	
}


double dot(PT p, PT q) 
{
	return (p.x * q.x) + (p.y * q.y);
}

double dist2(PT p, PT q)
{
	return dot(p-q, p-q); 
}

PT ProjectPointSegment(PT a, PT b, PT c) 
{
	double r = dot(b-a, b-a);
	if(fabs(r) < EPS) 
		return a;
	r = dot(c-a, b-a)/r;
	
	if(r < 0) 
		return a;
	if(r > 1) 
		return b;

	return a + (b - a ) *r ;
}

bool PointOnPolygon(const vector < PT > &p, PT q) 
{
	for (int i = 0; i < p.size(); i++)
		if (dist2(ProjectPointSegment(p[i], p[(i +1) % p.size()], q), q) < EPS)
			return true;
	return false;
}

bool PointInPolygon(const vector< PT > &p, PT q) 
{
	bool c = 0;
	for(int i = 0; i < p.size(); i++) 
	{
		int j = (i +1) % p.size();
		
		if((p[i].y <= q.y && q.y < p[j].y || p[j].y <= q.y && q.y < p[i].y) &&
			q.x < p[i].x+(p[j].x - p[i].x)*(q.y - p[i].y)/(p[j].y - p[i].y))
			c = ! c ;
	}
	return c;
}

double cross(PT &a, PT &b, PT &c)
{
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

vector <PT> hull(vector <PT> &P)
{
	sort(P.begin(), P.end());

	int n = P.size();
	int k = 0;

	vector <PT> H(2*n);

	for(int i=0; i<n; i++)
	{
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) 
			k--;
		H[k++] = P[i];
	}

	for (int i = n-2, t = k+1; i >= 0; i--) 
	{
		while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}

	H.resize(k--);
	return H;
}