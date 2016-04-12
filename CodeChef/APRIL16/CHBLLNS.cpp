#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int r,g,b;
		cin>>r>>g>>b;

		int k;
		cin>>k;

		long long int sum = 0;
		if(r<k)
			sum += r;
		else
			sum += k-1;

		if(g<k)
			sum += g;
		else
			sum += k-1;

		if(b<k)
			sum += b;
		else
			sum += k-1;

		sum++;

		cout<<sum<<endl;
	}	
}