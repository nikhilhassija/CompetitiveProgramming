#include <bits/stdc++.h>

#define lli long long int 

using namespace std;

int main()
{
	lli n,k;
	cin>>n>>k;

	if(n<k+2)
		printf("%.20f\n",0.0);
	else
	{
		double ans = 1;
		for(int i=0;i<k+2;i++)
			ans /= 2.0;

		ans *= (n-k-1);

		printf("%.20f\n",ans);
	}
}