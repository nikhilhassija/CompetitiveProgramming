#include <bits/stdc++.h>

#define lli long long int

using namespace std;

lli kadane(lli *, lli);

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n;
		scanf("%d",&n);

		lli A[2*n];
		for(int i=0;i<n;i++)
			scanf("%lld",&A[i]);

		int l,r;
		scanf("%d %d",&l,&r);

		for(int i=0;i<n;i++)
			A[i+n] = A[i];

		l--; r--;

		if(l>r)
			swap(l,r);

		lli total_sum = 0;
		for(int i=0;i<n;i++)
			total_sum += A[i];

		lli sum_lr = 0;
		for(int i=l;i<r;i++)
			sum_lr += A[i];

		lli sum_rl = 0;
		for(int i=r;i<l+n;i++)
			sum_rl += A[i];

		lli max_lr = kadane(A+l,r-l);
		lli max_rl = kadane(A+r,n-(r-l));

		total_sum *= 2;
		lli ans = min(total_sum - sum_lr - 2*max_rl,total_sum - sum_rl - 2*max_lr);

		printf("%lld\n",ans);
	}
}

lli kadane(lli *A, lli n)
{
	if(n <= 0)
		return 0;
	else
	{
		lli tot_max = 0;
		lli cur_max = 0;

		for(int i=0;i<n;i++)
		{
			cur_max += A[i];

			tot_max = max(tot_max,cur_max);
			cur_max = max(0ll,cur_max);
		}

		return tot_max;
	}
}