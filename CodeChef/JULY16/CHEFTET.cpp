#include <bits/stdc++.h>

#define lli long long int 

using namespace std;

lli checksum(lli [], lli);

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		lli n;
		cin>>n;

		lli A[n+2],B[n+2];
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));

		for(int i=0;i<n;i++)
			cin>>B[i+1];

		for(int i=0;i<n;i++)
			cin>>A[i+1];

		lli sum = 0;
		for(int i=0;i<n;i++)
			sum += A[i+1] + B[i+1];

		if(sum%n)
			printf("-1\n");
		else
		{
			lli x = sum/n;
			lli f = 0;

			for(int i=1;i<=n;i++)
			{
				if(A[i] > x || B[i] > x)
				{
					f = 1;
					break;
				}
				else
				{
					lli X[3] = {B[i-1],B[i],B[i+1]};

					if(checksum(X,x-A[i]))
					{
						B[i-1] = X[0];
						B[i] = X[1];
						B[i+1] = X[2];

						A[i] = x;
					}
					else
					{
						f = 1;
						break;
					}
				}
			}

			for(int i=0;i<=n;i++)
				f += B[i+1];

			for(int i=0;i<n;i++)
				if(x != A[i+1])
					f = 1;
			if(f)
				printf("-1\n");
			else
				printf("%lld\n",x);
		}
	}
}

lli checksum(lli X[3], lli sum)
{
	if(sum == 0)
		return 1;
	else if(sum == (X[0]))
		X[0] = 0; 
	else if(sum == (X[0] + X[1]))
		X[0] = X[1] = 0;
	else if(sum == (X[2] + X[0]))
		X[2] = X[0] = 0;
	else if(sum == (X[0] + X[1] + X[2]))
		X[0] = X[1] = X[2]= 0;
	else if(sum == (X[1]))
		X[1] = 0;
	else if(sum == (X[2]))
		X[2] = 0;
	else if(sum == (X[1] + X[2]))
		X[1] = X[2] = 0;
	else
		return  0;

	return 1;
}