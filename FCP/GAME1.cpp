#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int t,n,x,i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cin>>x;
		n--;
		while(n--)
		{
			cin>>i;
			x = __gcd(i,x);
		}
		cout<<x<<endl;
	}
	return 0;
}