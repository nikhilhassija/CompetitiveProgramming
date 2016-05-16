#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int a,m,l=0;
		string O;

		cin>>a;
		cin>>O;

		if(O == "INDIAN")
			m = 200;
		else
			m = 400;

		while(a--)
		{
			string A;
			cin>>A;

			if(A == "CONTEST_WON")
			{
				l += 300;

				int r;
				cin>>r;
				if(r < 20)
					l += 20 - r;
			}
			else if(A == "TOP_CONTRIBUTOR")
				l += 300;
			else if(A == "BUG_FOUND")
			{
				int s;
				cin>>s;

				l += s;
			}
			else
				l += 50;
		}

		cout<<l/m<<endl; 
	}
}