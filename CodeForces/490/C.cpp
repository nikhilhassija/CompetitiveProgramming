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

lli binpow(lli, lli, lli);

int main()
{
	string S;
	cin >> S;

	lli a, b;
	cin >> a >> b;

	for(auto &s: S)
		s -= '0';

	int n = S.size();
	int L[n];
	mset(L);

	lli s = 0;
	for(int i = 0; i < n; i++)	
	{
		s = (s * 10) + S[i];

		s %= a;

		L[i] = (not s);
	}

	int R[n];
	mset(R);

	s = 0;
	for(int i = n - 1; i > 0; i--)
	{
		s = (S[i] * (binpow(10, n - 1 - i, b))) + s;

		s %= b;

		R[i] = (S[i]) and (not s);
	}

	for(auto &s: S)
		s += '0';

	for(int i = 0; i < n; i++)
	{
		if(L[i] and R[i + 1])
		{
			cout << "YES" << endl;
			cout << S.substr(0, i + 1) << endl;
			cout << S.substr(i + 1) << endl;
	
			return 0;
		}
	}

	cout << "NO" << endl;

	return (0-0);	
}

lli binpow(lli a, lli b, lli m)
{
	lli r = 1;

	while(b)
	{
		if(b % 2)
			r = (r * a) % m;

		a = (a * a) % m;
		b /= 2;
	}

	return r;
}