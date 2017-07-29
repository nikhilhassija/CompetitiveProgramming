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
	int n;
	cin >> n;

	lli A[n];
	for(int i = 0; i < n; i++)
		cin >> A[i];

	lli sum = 0;
	for(int i = 0; i < n; i++)
		sum += A[i];

	if(sum % 3)
	{
		cout << 0 << endl;
		return 0;
	}

	lli s = sum / 3;

	lli pre = 0;
	lli suf = 0;

	for(int i = 0; i < n - 2; i++)
		pre += A[i];

	suf = A[n-1];

	lli ans = 0;
	lli cnt = 0;

	for(int i = n - 3; i >= 0; i--)
	{
		if(suf == s)
		{
			cnt++;
		}

		if(pre == s)
		{
			ans += cnt;
		}

		pre -= A[i];
		suf += A[i + 1];
	}

	cout << ans << endl;

	return (0-0);	
}