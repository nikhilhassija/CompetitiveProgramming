#include <bits/stdc++.h>

#define lli long long int

const lli MAX_N = 1e5 + 5;
const lli MOD   = 1e9 + 7;

struct mypair
{
	long double l;
	lli p;
};

lli F[MAX_N];

lli n;

mypair P[MAX_N];

void init();
void update(lli, lli);

lli powmod(lli, lli);

int main()
{
	scanf("%lld",&n);
	
	for(lli i=0;i<n;i++)
		scanf("%lld",&F[i]);
	
	if(n <= 1000)
	{
		lli q;
		scanf("%lld",&q);

		while(q--)
		{
			lli t;
			scanf("%lld",&t);

			if(t == 1)
			{
				lli p,f;
				scanf("%lld %lld",&p,&f);

				F[p-1] = f;
			}

			if(t == 2)
			{
				lli r;
				scanf("%lld",&r);

				lli p = 1;
				for(lli i=0;i<n;i+=r)
				{
					p *= F[i];
					p %= MOD;
				}

				if(n <= 10)
				{
					lli d = p;
					while(d/10) d /= 10;
						
					printf("%lld %lld\n",d%10,p);
				}
				else
				{
					long double d = 0;
					for(lli i=0;i<n;i+=r)
						d += log10l(F[i]);

					d -= int(d);

					printf("%lld %lld\n",(lli)(pow(10,d)),p);
				}
			}
		}
	}
	else
	{
		for(lli i=0;i<n;i++)
		{
			P[i].p = 1;
			P[i].l = 0;
		}

		init();
		
		lli q;
		scanf("%lld",&q);
		
		while(q--)
		{
			lli t;
			scanf("%lld",&t);

			if(t == 1)
			{
				lli p,f;
				scanf("%lld %lld",&p,&f);
				p--;

				if(p)
					update(p,f);
				
				F[p] = f;
			}

			if(t == 2)
			{
				lli r;
				scanf("%lld",&r);

				long double l = P[r].l + log10l(F[0]);
				l -= (lli)(l);
				lli d = pow(10,l);

				lli p = P[r].p * F[0];
				p %= MOD;

				printf("%lld %lld\n",d,p);
			}
		}
	}
}

lli powmod(lli a, lli b)
{
	lli ans = 1;

	while(b)
	{
		if(b & 1)
		{
			ans *= a;
			ans %= MOD;
		}

		a *= a;
		a %= MOD;

		b /= 2;
	}

	return ans;
}

void init()
{
	for(lli i=0;i<n;i++)
	{
		long double l = log10l(F[i]);
		lli s = (lli)sqrt(i);
		
		for(lli f=1;f<=s;f++)
		{
			if(i%f == 0)
			{
				P[f].l += l;

				P[f].p *= F[i];
				P[f].p %= MOD;
				
				if(f != i/f) // f != s
				{
					lli g = i/f;

					P[g].l += l;
					
					P[g].p *= F[i];
					P[g].p %= MOD;
				}
			}
		}
	}
}

void update(lli p, lli f)
{
	lli fp = F[p];
	F[p] = f;

	lli inv = powmod(fp, MOD-2);

	long double lp = log10l(fp);
	long double ln = log10l(F[p]);
	
	lli s = (lli)sqrt(p);
	
	for(lli i=1;i<=s;i++)
	{
		if(p%i == 0)
		{
			P[i].l += (ln - lp);

			P[i].p *= inv;
			P[i].p %= MOD;

			P[i].p *= F[p];
			P[i].p %= MOD;
			
			if(i != p/i)
			{
				lli j = p/i;

				P[j].l += (ln - lp);

				P[j].p *= inv;
				P[j].p %= MOD;

				P[j].p *= F[p];
				P[j].p %= MOD;
			}
		}
	}
}