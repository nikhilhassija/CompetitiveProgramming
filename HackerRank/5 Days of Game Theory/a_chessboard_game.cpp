#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int x,y;
		cin>>x>>y;
		if((x+y)%2)
			printf("Second\n");
		else
			printf("First\n");
	}
}