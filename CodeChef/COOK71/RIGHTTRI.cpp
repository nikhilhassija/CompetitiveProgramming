#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		long long int h,s;
		cin>>h>>s;

		if(((h*h)-(4*s)) >= 0)
		{
			long double c = h;
			long double x = h;
			x *= x;

			long double a = (x) - (sqrt((x-4*s)*(x+4*s)));
			a /= 2.0;
			long double b = x - (a);
			a = sqrt(a);
			b = sqrt(b);

			printf("%.5Lf %.5Lf %.5Lf\n",a,b,c);
		}
		else
			printf("-1\n");
	}
}