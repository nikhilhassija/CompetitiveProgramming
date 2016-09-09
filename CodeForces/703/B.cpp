#include <bits/stdc++.h>

#define lli long long int

using namespace std;

int main()
{
	lli n,k;
	scanf("%lld%lld",&n,&k);

	lli A[n],C[n];
	memset(C,0,sizeof(C));
	for(int i=0;i<n;i++)
		scanf("%lld",&A[i]);

	lli x;
	for(int i=0;i<k;i++)
	{
		scanf("%lld",&x);
		C[x-1] = 1;
	}

	lli nc_sum = 0;
	lli cc_sum = 0;
	for(int i=0;i<n;i++)
	{
		if(C[i])
			cc_sum += A[i];
		else
			nc_sum += A[i];
	}

	lli ans_nc = 0;
	lli ans_cc = 0;
	for(int i=0;i<n;i++)
	{
		if(C[i])
		{
			ans_nc += nc_sum*A[i];
			ans_cc += (cc_sum - A[i])*A[i];
		}
	}

	lli ans = ans_nc + (ans_cc/2);
	for(int i=0;i<n;i++)
	{
		int j = (i+1)%n;

		if(C[i] == 0 && C[j] == 0)
			ans += A[i]*A[j];
	}

	printf("%lld\n",ans);
}