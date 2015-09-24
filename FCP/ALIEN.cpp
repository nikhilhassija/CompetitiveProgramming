#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	string S = "01121002";
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<S[n%8]<<endl;
	}
	return 0;
}