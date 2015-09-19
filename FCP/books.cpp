#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio();
	int n,s=0,p=9;
	cin>>n;
	while(n>0)
	{
		s += n;
		n -= p;
		p *= 10;
	}
	cout<<s<<endl;
	return 0;
}