#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))
#define fastio() ios_base::sync_with_stdio(0); cin.tie(NULL)

using namespace std;

int main()
{
	lli n, p, q, r;
	cin >> n >> p >> q >> r;

	lli A[n];
	for (int i = 0; i < n; i++)
		cin >> A[i];

	lli P[n], Q[n], R[n];
	for (int i = 0; i < n; i++)
	{
		P[i] = A[i] * p;
		Q[i] = A[i] * q;
		R[i] = A[i] * r;
	
		if (i)
		{
			P[i] = max(P[i], P[i - 1]);
			Q[i] = max(P[i], P[i - 1]);
			R[i] = max(P[i], P[i - 1]);
		}
	}

	lli pm = -;


	for (int i = 0; i < n; i++)
	{

	}
	return (0-0);	
}