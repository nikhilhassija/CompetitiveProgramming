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
	int n, k;
	cin >> n >> k;

	string S;
	cin >> S;

	int L[26], R[26], O[26];

	mset(R);
	mset(O);
	for(int i = 0; i < 26; i++)
		L[i] = n;

	for(int i = 0; i < n; i++)
	{
		int x = S[i] - 'A';

		L[x] = min(L[x], i);
		R[x] = max(R[x], i);
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 26; j++)
		{
			if(i == L[j])
				O[j] = 1;

			if(i > R[j])
				O[j] = 0;
		}

		int s = 0;
		for(int o: O)
			s += o;

		if(s > k)
		{
			cout << "YES" << endl;
			return 0;
		}
	}
	
	cout << "NO" << endl;

	return (0-0);	
}