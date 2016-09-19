#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		string S;
		cin>>S;

		int c = 0;
		int n = S.size();
		for(int i=0;i<n;i++)
			c += S[i] -'0';

		if(c == 1 || c == n-1)
			printf("Yes\n");
		else
			printf("No\n");
	}
}