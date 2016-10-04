#include <bits/stdc++.h>

#define lli unsigned long long

using namespace std;

const lli mod = 1e9 + 7;

inline lli lcm(lli, lli);

int main()
{
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	lli A[n];
	for(int i=0;i<n;i++)
		cin >> A[i];

	lli L[n+1];
	for(int i=0;i<=n;i++)
		L[i] = INT_MAX;

	for(int k=1;k<=n;k++)
	{
		lli l = 1;

		for(int i=0;i<k;i++)
			l = lcm(l,A[i]);

		L[k] = min(L[k],l);
		for(int i=k;i<n;i++)
		{
			l *= __gcd(l/A[i-k],A[i-k]);
			l /= A[i-k];

			l = lcm(l,A[i]);
			L[k] = min(L[k],l);
		}
	}

	while(m--)
	{
		int x;
		cin >> x;

		cout << L[x]%mod << '\n';
	}
}

inline lli lcm(lli a, lli b)
{
	return (a/__gcd(a,b))*b;
} 