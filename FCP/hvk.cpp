#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int w,m;
	cin>>w>>m;
	while(m)
	{
		if((m-1)%w==0)
			m = (m-1)/w;
		else if((m+1)%w==0)
			m = (m+1)/w;
		else if(m%w==0)
			m = m/w;
		else
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}
