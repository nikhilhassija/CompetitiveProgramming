#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t,n,x,s;
	cin>>t;
	while(t--)
	{
		s = 0;
		cin>>n;
		while(n--)
		{
			cin>>x;
			s += x/3;
		}
		cout<<s<<endl;
	}
}