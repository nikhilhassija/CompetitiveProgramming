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

int main()
{
	int n, k;
	cin >> n >> k;

	vector <lli> P;
	vector <lli> A(n);

	if(k == 1)
	{
		P.pb(1ll);
	}	
	else if(k == -1)
	{
		P.pb(-1ll);
		P.pb(1ll);
	}
	else
	{
		for(lli i=1; abs(i)<=1e15; i*=k)
		{
			P.pb(i);
		}
	}

	for(int i=0; i<n; i++)
		cin >> A[i];

	lli C[n+1];
	C[0] = 0;
	for(int i=1; i<=n; i++)
		C[i] = C[i-1] + A[i-1];

	map <lli, lli> M;
	lli ans = 0;
	for(int i=n; i>=0; i--)
	{
		for(lli j: P)
		{
			if(M.find(j + C[i]) != M.end())
				ans += M[j + C[i]];
		}

		if(M.find(C[i]) != M.end())
			M[C[i]] += 1;
		else
			M[C[i]] = 1;
	}

	cout << ans << endl;
}