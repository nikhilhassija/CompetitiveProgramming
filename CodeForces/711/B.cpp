#include <bits/stdc++.h>

#define lli long long int

using namespace std;

int main()
{
	lli n;
	cin>>n;

	lli A[n][n];
	for(lli i=0;i<n;i++)
		for(lli j=0;j<n;j++)
			cin>>A[i][j];

	if(n == 1)
	{
		printf("1\n");
		return 0;
	}

	lli x,y;
	for(lli i=0;i<n;i++)
	{
		for(lli j=0;j<n;j++)
		{
			if(A[i][j] == 0)
			{
				x = i;
				y = j;
			}
		}
	}

	lli mnrsum = 0;
	lli mxrsum = 0;
	for(lli i=0;i<n;i++)
	{
		if(x == i)
			continue;

		lli sum = 0;
		for(lli j=0;j<n;j++)
			sum += A[i][j];

		if(mnrsum)
			mnrsum = min(mnrsum,sum);
		else
			mnrsum = sum;

		if(mxrsum)
			mxrsum = max(mxrsum,sum);
		else
			mxrsum = sum;
	}


	if(mnrsum == mxrsum)
	{
		lli rsum = mxrsum;

		lli mncsum = 0;
		lli mxcsum = 0;
		for(lli j=0;j<n;j++)
		{
			if(y == j)
				continue;

			lli sum = 0;
			for(lli i=0;i<n;i++)
				sum += A[i][j];

			if(mncsum)
				mncsum = min(mncsum,sum);
			else
				mncsum = sum;

			if(mxcsum)
				mxcsum = max(mxcsum,sum);
			else
				mxcsum = sum;
		}

		if(mncsum == mxcsum)
		{
			lli csum = mxcsum;

			if(csum == rsum)
			{
				lli rxsum = 0;
				for(lli i=0;i<n;i++)
					rxsum += A[x][i];

				lli cxsum = 0;
				for(lli i=0;i<n;i++)
					cxsum += A[i][y];

				lli rdx = rsum - rxsum;
				lli cdx = csum - cxsum;

				if(rdx == cdx)
				{
					lli ans = rdx;

					A[x][y] = ans;

					lli d1 = 0;
					lli d2 = 0;
					for(lli i=0;i<n;i++)
					{
						d1 += A[i][i];
						d2 += A[i][n-i-1];
					}

					if(d1 == d2 && d1 == rsum)
						printf("%lld\n",ans);
					else
						printf("-1\n");
				} 
				else
					printf("-1\n");
			}
			else
				printf("-1\n");
		}
		else
			printf("-1\n");
	}
	else
		printf("-1\n");
}