#include <bits/stdc++.h>

using namespace std;

int mod(int x)
{
	return (x<0)?(-x):x;
}

int main()
{
	int t;
	int n,m,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		if(k<mod(n-m))
			cout<<(mod(n-m)-k)<<endl;
		else
			cout<<"0"<<endl;
	}
}