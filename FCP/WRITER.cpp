#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int m,n,i;
	string S;
	cin>>m>>n;
	cin>>S;
	while(n--)
	{
		cin>>S;
		if(S=="T")
		{
			cin>>S;
			m += S.size();
		}
		else if(S=="W")
		{
			cin>>i;
			m -= i;
		}
		else if(S=="C")
		{
			cout<<m<<endl;
		}
	}
	return 0;
}