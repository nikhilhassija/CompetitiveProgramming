#include <bits/stdc++.h>

using namespace std;

void findmax(long long int *, int, int *, int *, long long int *);

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;

		long long int A[n+6];
		A[0] = A[1] = A[2] = A[n+3] = A[n+4] = A[n+5];
		for(int i=0;i<n;i++)
			cin>>A[i+3];

		long long int m =A[3];
		for(int i=0;i<n;i++)
			m = max(m,A[i+3]);

		if(m>0)
		{
			int l,r;
			long long int sum;
			findmax(A+3,n,&l,&r,&sum);
			l += 3;
			r += 3;

			m = A[l];
			for(int i=l;i<=r;i++)
				m = min(m,A[i]);

			sum = max(sum-m,max(sum+A[l-2],sum+A[r+2]));
			printf("%lld\n",sum);
		} 
		else
			printf("%lld\n",m);
	}
}

void findmax(long long int * A, int n, int *l, int *r, long long int * sum)
{
	long long int m = 0;
	long long int s = 0;
	int sl = 0;
	int sr = 0;

	for(int i=0;i<n;i++)
	{
		s += A[i];

		if(s < 0)
		{
			s = 0;
			l = i+1;
		}
		else if(s > s)
	}
}
