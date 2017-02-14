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

lli tonum(lli, lli, lli);

int main()
{
	int n;
	cin >> n;

	lli A[n+1];
	for(int i=0; i<n; i++)
		cin >> A[i];

	A[n] = A[0];

	lli sum = 0;
	lli sig = 0;
	for(int i=1; i<=n; i++)
	{
		sum += A[i];
		sig += i;
	}	

	if(sum % sig == 0)
	{
		lli num = sum / sig;

		lli c = 0;

		for(int i=0; i<n; i++)
			if(A[i+1] - A[i] != num)
				c += tonum(A[i+1] - A[i], num, n);

		if(c == num)
			printf("YES\n");
		else
			printf("NO\n");
	}
	else
		printf("NO\n");
}

lli tonum(lli cur, lli tar, lli n)
{
	lli c = 0;

	while(cur < tar)
	{
		c++;
		cur += n;
	}

	return c;
}