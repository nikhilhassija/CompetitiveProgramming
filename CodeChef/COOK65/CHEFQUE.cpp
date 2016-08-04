#include <bits/stdc++.h>

#define lli unsigned int 

using namespace std;

bitset<2147483648> B;

int main()
{
	lli q,s,a,b,sum=0;
	cin>>q>>s>>a>>b;

	while(q--)
	{
		lli x = s/2;
		
		if(s%2)
		{
			if(B[x] == 0)
			{
				B[x] = 1;
				sum += x;
			}
		}
		else
		{
			if(B[x] == 1)
			{
				B[x] = 0;
				sum -= x;
			}
		}
		
		s = (a*s) + b;
	}

	printf("%lld\n",sum);
}
