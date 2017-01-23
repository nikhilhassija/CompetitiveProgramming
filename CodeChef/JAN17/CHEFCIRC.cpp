#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define pdd pair <double, double>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))
#define fastio() ios_base::sync_with_stdio(0)

using namespace std;

const double inf = 1e18;

pdd cent(pdd, pdd);
double dist(pdd, pdd);

int main()
{
	int n, m;
	cin >> n >> m;

	if(n == 1)
	{
		printf("0\n");
		return 0;
	}

	vector < pdd > A(n);

	for(pdd &p: A)
		cin >> p._F >> p._S;

	double ans = inf;

	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			pdd centre = cent(A[i], A[j]);
			double radius = dist(A[i], A[j])/2.0;

			int temp = 0;

			for(int k=0;k<n;k++)
				if(dist(centre, A[k]) <= radius)
					temp++;

			if(temp >= m)
				ans = min(ans, radius);
		}
	}

	printf("%.5f\n", ans);
}

pdd cent(pdd a, pdd b)
{
	double x = (a._F + b._F)/2.0;
	double y = (a._S + b._S)/2.0;

	return {x, y};
}

double dist(pdd a, pdd b)
{
	double x = (a._F - b._F) * (a._F - b._F);
	double y = (a._S - b._S) * (a._S - b._S);

	return sqrt(x + y);
}