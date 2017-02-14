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

const lli mod = 1e9 + 7;

int check(char *, int, int *);
pii minmax(string, int *);

int main()
{
	int n;
	cin >> n;

	string S;
	cin >> S;

	int A[26];
	for(int i=0; i<26; i++)
		cin >> A[i];

	char s[S.size() + 5];
	memset(s, 0, sizeof(s));
	for(int i=0; i<n; i++)
		s[i] = S[i];

	int V[n][n];
	memset(V, 0, sizeof(V));

	for(int i=0; i<n; i++)
		for(int j=i; j<n; j++)
			V[i][j] = check(s+i, j-i+1, A);

	lli DP[n][n];
	memset(DP, 0, sizeof(DP));
	for(int i=0; i<n; i++)
		DP[0][i] = V[0][i];

	for(int i=1; i<n; i++)
	{
		lli sum = 0;
		for(int j=0; j<i; j++)
			sum += DP[j][i-1];

		for(int j=i; j<n; j++)
		{
			if(V[i][j])
			{
				DP[i][j] += sum; 
				DP[i][j] %= mod;
			}
		}
	}

	lli ans = 0;
	for(int i=0; i<n; i++)
		ans += DP[i][n-1];

	cout << ans << endl;

	auto p = minmax(S, A);
	for(int i=n-1; i>=0; i--)
		if(V[i][n-1])
			p.first = max(p.first, n-i);

	cout << p.first << endl;
	cout << p.second << endl;
}

int check(char * s, int n, int * A)
{
	int C[26];
	memset(C, 0, sizeof(C));

	for(int i=0; i<n; i++)
		C[s[i] - 'a']++;

	for(int i=0; i<26; i++)
		if(C[i] && n > A[i])
			return 0;

	return 1;
}

pii minmax(string S, int * A)
{
	int C[26];
	memset(C, 0, sizeof(C));

	int a = 0;
	int b = 0;
	int l = 0;

	for(int i=0; i<S.size(); i++)
	{
		C[S[i] - 'a']++;
		for(int j=0; j<26; j++)
		{
			if(C[j] && i-l + 1 > A[j])
			{
				a = max(a, i-l);
				b++;
				l = i;

				memset(C, 0, sizeof(C));
				C[S[i] - 'a'] = 1;
				break;
			}
		}
	}
	b++;

	return {a, b};
}