#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))
#define fastio() ios_base::sync_with_stdio(0)

using namespace std;

lli ncr(lli, lli, lli);

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		lli n, k, m;
		cin >> n >> k >> m;

		lli x = (n / k) + (n % k != 0);

		lli y = (x * k) - n;

		cout << x << " ";
		cout << ncr(y + x - 1, y, m) << endl;
	}

	return (0-0);	
}

int isprime(lli x)
{
	for(lli i=2; i<=sqrt(x); i++)
		if(x % i == 0)
			return 0;

	return 1;
}

lli binexp(lli a, lli b, lli p)
{
	lli res = 1;

	while(b)
	{
		if(b % 2)
			res = (res * a) % p;

		b /= 2;
		a = (a * a) % p;
	}

	return res;
}

lli ncr(lli n, lli r, lli m)
{
	if(isprime(m))
	{
		assert(0);
		lli ans = 1;
		lli p = m;

		while(n && r)
		{	

			lli x = n / p;
			lli y = r / p;

			if(x < y)
				ans = 0;
			else
			{
				y = min(x-y, y);

				for(lli i=(x-y+1); i<=x; i++)
					ans = (ans * (i % p)) % p;

				for(lli i=1; i<=y; i++)
					ans = (ans * binexp(i, p-2, p)) % p;
			}			

			n /= p;
			r /= p;
		}

		return ans;
	}
	else
	{
		return 0;
	}
}