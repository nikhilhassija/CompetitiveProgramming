#include <bits/stdc++.h>

#define lli int

using namespace std;

const lli N = 1005;

int NC2[N];

void init();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	init();

	lli t;
	scanf("%d",&t);

	while(t--)
	{
		lli n;
		scanf("%d",&n);

		lli A[n];
		for(lli i=0;i<n;i++)
			scanf("%d",&A[i]);

		pair <lli,lli> P[n];
		for(lli i=0;i<n;i++)
			P[i] = make_pair(A[i],i);

		sort(P,P+n);

		int c = 0;
		A[P[0].second] = c;
		for(int i=1;i<n;i++)
		{
			if(P[i].first != P[i-1].first)
				c++;
			A[P[i].second] = c; 
		}

		int MAX_C = c+1;

		lli C[MAX_C];
		lli ans = 0;
		for(lli i=0;i<n;i++)
		{
			memset(C,0,sizeof(C));
			for(lli j=i;j<n;j++)
			{
				C[A[j]]++;
				lli x = 0;
				for(lli k=j+1;k<n;k++)
				{
					if(C[A[k]])
					{
						ans += NC2[x+1];
						x = 0;
					}
					else
						x++;
				}
				ans += NC2[x+1];
			}
		} 

		printf("%d\n",ans);
	}
}

void init()
{
	for(int i=0;i<N;i++)
		NC2[i] = (i*(i-1))/2;
}