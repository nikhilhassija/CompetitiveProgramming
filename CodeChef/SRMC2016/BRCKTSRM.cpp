#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int x=0;
		string S;
		cin>>S;

		for(int i=0;i<S.size();i++)
		{
			if(S[i] == '(')
				x++;
			else if(x>0)
				x--;
			else
			{
				x = -1;
				break;
			}
		}

		if(x == -1 || x>0)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
}