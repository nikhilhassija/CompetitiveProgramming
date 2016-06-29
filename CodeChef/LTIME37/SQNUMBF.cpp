#include <bits/stdc++.h>

#define lli long long int 

using namespace std;

const lli N = 10000000;
int lp[N+1];
vector <lli> pr;

void init();

int main()
{
	init();

	lli t;
	scanf("%lld",&t);

	lli F[10000];
	
	while(t--)
	{
		lli n;
		scanf("%lld",&n);

		lli A[n];
		for(lli i=0;i<n;i++)
			scanf("%lld",&A[i]);

		lli c = 0;

		for(int j=0;j<n;j++)
		{
			for(int i=0;i<pr.size() && pr[i] <= A[j];i++)
			{
				while(A[j]%pr[i] == 0)
				{
					A[j] /= pr[i];
					F[c++] = pr[i];
				}
			}
			
			if(A[j] != 1)
				F[c++] = A[j];
		}

		sort(F,F+c);

		for(int i=0;i<c-1;i++)
			if(F[i] == F[i+1])
			{
				printf("%lld\n",F[i]);
				break;
			}
	}

}


void init()
{
	for (lli i=2;i<=N;i++)
	{
		if (lp[i] == 0)
		{
			lp[i] = i;
			pr.push_back(i);
		}

		for (lli j=0; j<(lli)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
			lp[i * pr[j]] = pr[j];
	}
}