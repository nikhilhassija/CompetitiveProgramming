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

		int n = S.size();
		int f = 1;
		for(int i=0;i<n/2 && f;i++)
		{
			int j = n - i - 1;
			if(S[i] == '.' && S[j] == '.')
				S[i] = S[j] = 'a';
			else if(S[i] == '.' || S[j] == '.')
				S[i] = S[j] = max(S[i],S[j]);
			else
				f = (S[i] == S[j]);
		}

		if(n%2 && S[n/2] == '.')
			S[n/2] = 'a';

		if(f)
			cout<<S<<'\n';
		else
			printf("-1\n");
	}
}