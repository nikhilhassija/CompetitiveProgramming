#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;

	int mn = n/7;
	mn *= 2;
	int mx = mn;
	if(n%7)
	{
		if(n%7 == 1)
			mx += 1;
		else
			mx += 2;
		if(n%7 == 6)
			mn ++;
	}

	printf("%d %d\n",mn,mx);
}