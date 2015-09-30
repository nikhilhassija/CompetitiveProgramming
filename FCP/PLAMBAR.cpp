#include <bits/stdc++.h>

using namespace std;

int pcheck(int);

int main()
{
	ios_base::sync_with_stdio(false);
	int t,n,m;
	cin>>t;
	while(t--)
	{
		m = 1;
		cin>>n;
		for(int i=1;i<=sqrt(n);i++)
			if(n%i==0)
			{
				if(pcheck(i))
					m = max(i,m);
				if(pcheck(n/i))
				{
					m = max(n/i,m);
					break;
				}
			}
		cout<<m<<endl;
	}
	return 0;
}

int pcheck(int a)
{
	int f = 1;
	for(int i=2;i<=sqrt(a);i++)
		if(a%i==0)
		{
			f = 0;
			break;
		}
	return f;
}