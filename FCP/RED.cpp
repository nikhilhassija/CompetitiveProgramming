#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,k,i,x,f=1;
	cin>>n>>k;
	x = n;
	while(n--)
	{
		cin>>i;
		if(i==0 && f)
		{
			x -= n;
			f = 0;
		}
	}
	x += f;
	cin>>n;
	while(n--)
	{
		cin>>i;
		if(i<=k && i<x)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}