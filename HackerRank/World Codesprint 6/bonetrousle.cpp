#include <bits/stdc++.h>

#define lli long long int

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		lli n,k,b;
		cin>>n>>k>>b;

		lli mxb = (b*(b+1))/2;
		lli mxk = (k*(k+1))/2;
		if(n >= mxb && n <= mxk)
		{
			lli A[b];
			for(lli i=0;i<b;i++)
			{
				A[i] = i+1;
				n -= (i+1);
			}

			lli i = b-1;
			while(n && i>=0)
			{
				lli d = min(n,abs(A[i]-k));

				A[i] += d;

				k--;
				n -= d;
				i--;
			}

			if(n)
				printf("-1\n");
			else
			{
				for(int i=0;i<b;i++)
					printf("%lld ",A[i]);
				printf("\n");
			}
		}
		else
			printf("-1\n");
	}
}