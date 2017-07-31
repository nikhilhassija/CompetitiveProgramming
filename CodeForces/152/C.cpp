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
	int n, m;
	cin >> n >> m;

	string S[n];
	for(int i = 0; i < n; i++)
		cin >> S[i];

	lli C[m][26];
	mset(C);
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			C[j][S[i][j] - 'A'] = 1;

	lli MOD = 1e9 + 7;
	lli N[m];
	mset(N);

	for(int i = 0; i < m; i++)
		for(int j = 0; j < 26; j++)
			N[i] += C[i][j];

	lli ans = 1;

	for(int i = 0; i < m; i++)
		ans = (ans * N[i]) % MOD;

	cout << ans << endl;

	return (0-0);	
}