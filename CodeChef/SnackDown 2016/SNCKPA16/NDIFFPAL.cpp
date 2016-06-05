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

		while(n--)
			printf("%c",(char)(n%26)+'a');
		printf("\n");
	}
}