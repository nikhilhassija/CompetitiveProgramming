#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int64_t t,n,k,x,s;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		s = 0;
		while(n--)
		{
			cin>>x;
			s += x%k;
			s = s%(1000000009);
		}
		cout<<(s%(1000000009))<<endl;
	}
	return 0;
}