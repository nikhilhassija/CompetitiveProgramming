#include <bits/stdc++.h>

using namespace std;

int64_t pod(int64_t n)
{
	int64_t p = 1;
	while(n)
	{
		p *= n%10;
		n /= 10;
	}
	return p;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int64_t t,l,r,p;
	cin>>t;
	while(t--)
	{
		cin>>l>>r;
		if(r-l>4)
			cout<<"0"<<endl;
		else
		{
			p = r;
			while(l<r)
				p *= l++;
			cout<<pod(p)<<endl;
		}
	}
	return 0;
}