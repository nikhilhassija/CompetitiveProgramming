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

int notPrime(int);

int main()
{
	for(int i=1;i<=1000;i++)	
	{
		int n = i;

		// cin >> n;

		for(int i = 1; i <= 1000; i++)
			if(notPrime(n*i + 1))
			{
				printf("%d\n", i);	
				break;
			}
	}
}

int notPrime(int n)
{
	for(int i=2; i<=sqrt(n); i++)
		if(n % i == 0)
			return 1;

	return 0;
}