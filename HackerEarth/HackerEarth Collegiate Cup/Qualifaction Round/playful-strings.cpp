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

		int f = 1;
		for(int i=0;i<S.size() - 1;i++)
		{
			if(abs(S[i] - S[i+1]) != 1)
			{
				f = 0;
				if(abs(S[i] - S[i+1]) == 25)
					f = 1;
			}
		}

		if(f)
			printf("YES\n");
		else
			printf("NO\n");
	}
}