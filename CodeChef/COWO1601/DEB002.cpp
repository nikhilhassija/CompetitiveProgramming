#include <bits/stdc++.h>

using namespace std;

long long int solve(long long int a, long long int b, long long int c)
{
	long long int d = b*b - 4*a*c;

	if(d<0)
		return -1;
	else
	{
		long long int root1 = (-b - sqrt(d))/(2*a);
		long long int root2 = ceil((-b + sqrt(d))/(2*a));

		if(max(root1,root2)<0)
			return -1;
		else
		{
			long long int ans = min(root1,root2);
			if(ans<0)
			{
				ans = max(root1,root2);
				return ans;
			}
			return ans;
		}
	}
}

int main()
{
	long long int t;
	cin>>t;

	while(t--)
	{
		long long int a,b,c,k;
		cin>>a>>b>>c>>k;

		c -= k;

		cout<<solve(a,b,c)<<endl;
	}
}