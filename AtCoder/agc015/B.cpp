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
	string S;
	cin >> S;

	int n = S.size();
	lli ans = 0;

	for(int i=0; i<n; i++)
	{
		ans += (n-1);

		if(S[i] == 'U')
			ans += i;
		else
			ans += (n-i-1);
	}

	cout << ans << endl;
	return (0-0);	
}