#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	string S;
	cin >> S;

	int g;
	for(int i=0;i<n;i++)
		if(S[i] == 'G')
			g = i;

	for(int i=g;i>=0;i-=k)
	{
		if(S[i] == '#')
			break;

		if(S[i] == 'T')
		{
			printf("YES\n");
			return 0;
		}
	}

	for(int i=g;i<n;i+=k)
	{
		if(S[i] == '#')
			break;

		if(S[i] == 'T')
		{
			printf("YES\n");
			return 0;
		}
	}

	printf("NO\n");	
}