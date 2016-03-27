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

		if(S.size() == 2 && S[0] == S[1])
				cout<<S[0]<<endl;
		else if(S.size() == 3)
		{
			int x = 0;
			for(int i=0;i<3;i++)
				if(S[i] == 'A')
					x++;
			if(x == 1)
				printf("B\n");
			else if(x == 2)
				printf("A\n");
			else
				printf("-1\n");
		}
		else
			printf("-1\n");
	}
}