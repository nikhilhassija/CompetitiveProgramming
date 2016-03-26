#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		string S;
		int x=0,y=0;

		cin>>S;

		for(int i=0;i<S.size();i++)
		{
			switch(S[i])
			{
				case 'N': y++;break;
				case 'E': x--;break;
				case 'W': x++;break;
				case 'S': y--;break;
			}
		}

		if(y<0)
			cout<<"SOUTH";
		if(y>0)
			cout<<"NORTH";

		if(x<0)
			cout<<"EAST";
		if(x>0)
			cout<<"WEST";

		cout<<endl;
	}
}