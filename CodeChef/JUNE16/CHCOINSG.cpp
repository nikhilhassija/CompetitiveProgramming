#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;

		if(n%6)
			printf("Chef\n");
		else
			printf("Misha\n");
	}
}