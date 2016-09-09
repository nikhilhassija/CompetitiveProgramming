#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;

	int a,b,c=0,d=0;

	while(n--)
	{
		cin>>a>>b;

		c += (a>b);
		d += (b>a);
	}

	if(c>d)
		printf("Mishka\n");
	else if(d == c)
		printf("Friendship is magic!^^\n");
	else
		printf("Chris\n");
}