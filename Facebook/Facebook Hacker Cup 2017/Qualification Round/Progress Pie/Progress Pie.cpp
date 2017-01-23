#include <bits/stdc++.h>

using namespace std;

#define pdd pair <double, double>

const double PI = 3.141592653; 
const double tol = 1e-6;

double angle(pdd, pdd);
double dist(pdd, pdd); 

int main()
{
	int t;
	cin >> t;

	for(int i=0; i<t; i++)
	{
		double p, x, y;
		cin >> p >> x >> y;

		p *= 3.6;
		p += tol;

		double rad = angle({x-50, y-50}, {0, 50});
		double deg = rad * (180.0)/PI;
		
		double dst = dist({50,50}, {x,y});

		if(deg < 0)
			deg += 360;

		printf("Case #%d: ", i+1);
		
		if(deg <= p && dst <= 50.0)
			printf("black\n");
		else
			printf("white\n");
	}
}

double angle(pdd a, pdd b)
{
	double dot = a.first*b.first + a.second*b.second;
	double det = a.first*b.second - b.first*a.second;

	return atan2(det, dot);
}

double dist(pdd a, pdd b)
{
	double x = a.first - b.first;
	double y = a.second - b.second;

	return sqrt(x*x + y*y);
}