#include <bits/stdc++.h>

#define lli long long int

using namespace std;

int main()
{
	lli n,k;
	cin >> n >> k;

	lli A[n];
	for(int i=0;i<n;i++)
		cin >> A[i];

	if(n == 1)
		printf("0\n");
	else if(n == 2)
	{
		lli dif = abs(A[n-1] - A[0]);

		if(dif <= k)
			printf("%lld\n",(k-dif)%2);
		else
		{
			lli sum1 = dif + k;
			lli sum2 = dif - k;

			printf("%lld\n",min(abs(sum1),abs(sum2)));
		}
	}
	else
	{
		lli dif = abs(A[n-1] - A[0]);
		if(dif <= k)
			printf("0\n");
		else
			printf("%lld\n",dif-k);
	}
}