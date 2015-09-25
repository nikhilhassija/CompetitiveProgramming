#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int n,t,x,i;
	cin>>n>>t;
	while(t--)
	{
		cin>>i;
		x = n-i;
		if(x>0)
			while(x--)
				cout<<i<<endl;
		else
			cout<<"-1"<<endl;	
	}
	return 0;
}