#include <bits/stdc++.h>

#define lli long long int 

using namespace std;

const int N = 1e5 + 5;
const lli mod = 1e9 + 7;

inline lli MOD(lli x)
{
	if(x < 0)
		x += (((-x)/mod) + 2) * mod;
	return x % mod;
}

int main()
{
	int n, q;
	cin >> n >> q;

	lli F[N],a,b;
	cin >> F[0] >> F[1] 
		>> a >> b;

	for(int i=2;i<N;i++)
	{
		F[i] = a*F[i-2] + b*F[i-1];
		F[i] %= mod;
	}

	lli A[n+4];
	memset(A,0,sizeof(A));
	for(int i=0;i<n;i++)
		cin >> A[i+2];

	lli Q[n+4];
	memset(Q,0,sizeof(Q));

	while(q--)
	{
		lli l,r;
		cin >> l >> r;

		l++;
		r++;

		if(l < r)
		{
			Q[l] += F[0];
			Q[l] = MOD(Q[l]);

			Q[l+1] += F[1];
			Q[l+1] -= b*F[0];
			Q[l+1] = MOD(Q[l+1]);

			Q[r+1] -= F[r-l+1];
			Q[r+1] = MOD(Q[r+1]);

			Q[r+2] -= (a*F[r-l])%mod; //+ b*0
			Q[r+2] = MOD(Q[r+2]);
		}
		else
		{
			Q[l] += F[0];
			Q[l] = MOD(Q[l]);

			Q[l+1] -= b*F[0];
			Q[l+1] = MOD(Q[l+1]);

			Q[l+2] -= (a*F[0])%mod;
			Q[l+2] = MOD(Q[l+2]);
		}
	}

	for(int i=2;i<n+2;i++)
	{
		Q[i] += (a*Q[i-2] + b*Q[i-1])%mod;
		Q[i] = MOD(Q[i]);

		A[i] += Q[i];
		A[i] = MOD(A[i]);
	}

	for(int i=0;i<n;i++)
		printf("%lld ",A[i+2]);
	printf("\n");
}