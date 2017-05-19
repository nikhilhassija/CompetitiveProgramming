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

double geth(double a, double h)
{
	return sqrt(((double) 2.0) * a * h);
}

int main()
{
	int n, h;
	cin >> n >> h;

	double A = ((double) h) / ((double) 2.0);

	double a = A / ((double) n);

	for(int i=1; i<n; i++)
	{
		cout << fixed << setprecision(10) << 
		geth(((double) i) * a, (double) h) << " ";
	}
	cout << endl;

	return (0-0);	
}