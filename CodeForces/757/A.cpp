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

	int C[256];
	memset(C, 0, sizeof(C));

	for(int i=0;i<S.size();i++)
		C[S[i]]++;

	int ans = C['B'];

	ans = min(ans, C['u']/2);
	ans = min(ans, C['l']/1);
	ans = min(ans, C['b']/1);
	ans = min(ans, C['a']/2);
	ans = min(ans, C['s']/1);
	ans = min(ans, C['r']/1);

	cout << ans << endl;
}