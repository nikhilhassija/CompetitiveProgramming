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

int main()
{	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	double s, m, p;
	cin >> s >> m >> p;

	double diff = 1e5;
	double tol  = 1e-8;

	double l = 0;
	double h = 3 * s;
	double ans = 0;

	while(tol < (h - l))
	{
		double x = (l + h) / 2.0F;

		double debt = s;

		for(int i=0; i<m; i++)
		{
			double a = (debt * p) / 100.0F;
			double b = x - a;

			debt -= b;
 		}

 		if(abs(debt) > tol)
 		{
 			if(debt < 0)
 				h = x;
 			else
 				l = x;
 		}
 		else
 		{
 			ans = x; 
 			break;
 		}
	}

	printf("%.10F\n", ans);

	return (0-0);	
}