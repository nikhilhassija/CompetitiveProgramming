#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		long long int n,m;
		cin>>n>>m;
		if(min(n,m) == 1 && max(n,m) == 2)
			cout<<"Yes"<<endl;
		else if(n==1 || m==1)
			cout<<"No"<<endl;
		else if(n%2 == 0 || m%2==0)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
}