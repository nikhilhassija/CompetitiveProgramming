#include <bits/stdc++.h>

using namespace std;


int main()
{
	long long int x1,x2,y1,y2;
	long long int l1,l2,h1,h2;
	cin>>x1>>y1>>x2>>y2;
	l1 = (x1 - x2);
	l1 = max(l1,-l1);
	l1++;
	l2 = l1/2;
	l1 = l1/2 + l1%2;
	h1 = (y1 - y2);
	h1 = max(h1,-h1);
	h1++;
	h2 = h1/2;
	h1 = h1/2 + h1%2;
	cout<<(l1*h1 + l2*h2)<<endl;
}