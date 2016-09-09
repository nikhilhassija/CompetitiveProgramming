#include <bits/stdc++.h>

using namespace std;

int main()
{
	int x1,v1,x2,v2;
	cin>>x1>>v1>>x2>>v2;

	int d = x2 - x1;
	int v = v1 - v2;

	if(d*v > 0 && d%v == 0)
		printf("YES\n");
	else
		printf("NO\n");
}