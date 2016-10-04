#include <bits/stdc++.h>

#define lli long long int 

using namespace std;

int isprime(lli);

int main()
{
	lli a;
	cin>>a;

	if(a%2 == 0)
	{
		if(a/2 > 1)
		{
			lli x = a/2,m,n;
			for(lli i=1;i<=sqrt(x);i++)
			{
				if(x%i == 0)
				{
					m = i;
					n = x/i;
					if(m<n)
						swap(m,n);

					lli b,c;
					
					b = m*m - n*n;
					c = m*m + n*n;							
					printf("%lld %lld\n",b,c);
					return 0;
				}
			} 
		}
	}

	for(lli i=1;i<=sqrt(a);i++)
	{
		lli x = a - i*i;
		lli y = sqrt(x);

		if(y*y == x && y>1)
		{
			lli m,n;
			m = i;
			n = y;
			if(m<n)
				swap(m,n);

			lli b,c;

			b = 2*m*n;
			c = m*m - n*n;
			printf("%lld %lld\n",b,c);
			return 0;
		}
	}

	for(lli i=(a/2)+a%2;i>0;i--)
	{
		lli j = i-1;
		while((i*i)-(j*j) < a && j)
			j--;

		if(i*i - j*j == a && j)
		{
			lli m,n;
			m = i;
			n = j;

			if(m<n)
				swap(m,n);

			lli b,c;
			b = 2*m*n;
			c = m*m + n*n;
			printf("%lld %lld\n",b,c);
			return 0;
		} 
	}

	printf("-1\n");
}

int isprime(lli n)
{
	for(int i=2;i<=sqrt(n);i++)
		if(n%i==0)
			return 1;
	return 0;
}