#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int64_t t,n,m,q,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		cin>>q;
		while(q--)
		{
			cin>>k;
			cout<<(((n%k)?((n/k)+1):(n/k))%(1000000007))*(((m%k)?((m/k)+1):(m/k))%(1000000007))%(1000000007)<<endl;
		}	
	}
	return 0;
}