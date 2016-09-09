#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;

	string S[n];
	for(int i=0;i<n;i++)
		cin>>S[i];

	int f = 1;
	for(int i=0;i<n && f;i++)
	{
		if(S[i][0] == 'O' && S[i][1] == 'O')
		{
			S[i][0] = '+';
			S[i][1] = '+';
			f = 0;	
		}
		else if(S[i][3] == 'O' && S[i][4] == 'O')
		{
			S[i][3] = '+';
			S[i][4] = '+';
			f = 0;	
		}
	}

	if(f)
		printf("NO\n");
	else
	{
		printf("YES\n");
		for(int i=0;i<n;i++)
			cout<<S[i]<<endl;
	}
}