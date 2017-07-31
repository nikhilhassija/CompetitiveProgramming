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
	int n, p;
	cin >> n >> p;

	string S;
	cin >> S;

	for(int i = 0; i < n; i++)
		S[i] -= 'a';

	if(p > n / 2)
	{
		p = n - p + 1;
		reverse(S.begin(), S.end());
	}

	p--;

	int ans = 0;
	int C[n];
	mset(C);

	for(int i = 0; i < n / 2; i++)
	{
		int d = abs(S[i] - S[n - i - 1]);
		ans += min(d, 26 - d);
	
		if(S[i] != S[n - i - 1])
			C[i] = 1;
	}

	int l = n;
	int r = 0;
	for(int i = 0; i < n; i++)
		if(C[i])
		{
			l = min(l, i);
			r = max(r, i);			
		}

	if(not ans)
	{
		cout << 0 << endl;
		return 0;
	}

	if(r <= p)
		ans += p - l;
	else if(l >= p)
		ans += r - p;
	else
		ans += r - l + min(p - l, r - p);

	cout << ans << endl;

	return (0-0);	
}