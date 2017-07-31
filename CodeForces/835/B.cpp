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
	lli k;
	cin >> k;

	string S;
	cin >> S;

	lli C[10];
	mset(C);

	lli sum = 0;

	for(auto s: S)
	{
		C[s - '0']++;
		sum += s - '0';
	}

	lli ans = 0;
	lli ind = 0;

	while(sum < k)
	{
		while(not C[ind])
			ind++;

		lli d = 9 - ind;
		lli a = k - sum;
		lli x = min((a + d - 1) / d, C[ind]);

		C[ind] -= x;
		ans += x;

		sum += x * d;
	}

	cout << ans << endl;

	return (0-0);	
}