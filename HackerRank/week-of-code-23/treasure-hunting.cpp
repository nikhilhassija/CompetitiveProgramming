#include <bits/stdc++.h>

using namespace std;

int main()
{
	long double x,y,a,b;
	cin >> x >> y >> a >> b;

	long double k = (x*a + y*b)/(a*a + b*b);
	long double n = -(x*b - y*a)/(a*a + b*b);

	printf("%.9Lf\n%.9Lf\n",k,n);
}