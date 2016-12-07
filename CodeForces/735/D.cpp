#include <bits/stdc++.h>

#define lli long long int

using namespace std;

int isPrime(lli);

int main()
{
	lli n;
	cin >> n;

	if(isPrime(n))
		printf("1\n");
	else if(n % 2 == 0 || (isPrime(n-2)))
		printf("2\n");
	else
		printf("3\n");
}

int isPrime(lli x)
{
	lli s = sqrt(x);
	for(lli i=s;i>1;i--)
		if(x % i == 0)
			return 0;

	return 1;
}