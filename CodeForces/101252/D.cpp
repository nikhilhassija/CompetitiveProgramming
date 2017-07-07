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

lli A, B, C;

lli next(lli);

int main()
{
	#ifdef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	cin >> A >> B >> C;

	lli n = 2e7;
	lli x = 1;

	for(int i=0; i<n; i++)
		x = next(x);

	lli last = x;
	lli len  = 2*n;

	for(int i=1; i<=n; i++)
	{
		x = next(x);

		if(last == x)
		{
			len = i;
			break;
		}
	}

	if(len == 2*n)
	{
		cout << -1 << endl;
		return 0;
	}

	lli f = 1;
	lli s = 1;
	lli idx = 0;

	for(int i=0; i<len; i++)
		s = next(s);

	while(f != s)
	{
		f = next(f);
		s = next(s);

		idx++;
	}

	lli ans = idx + len;

	if(ans > n)
		cout << -1 << endl;
	else
		cout << ans << endl;

	return (0-0);	
}

lli next(lli x)
{
	return (A * x  + (x % B)) % C;
}
