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
	int n;
	cin >> n;

	string S[n];
	for (int i = 0; i < n; i++)
	{
		cin >> S[i];

		int f = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if(S[i] == S[j])
			{
				cout << "YES" << endl;
				f = 1;
				break;
			}
		}

		if (not f)
			cout << "NO" << endl;
	}
	
	return (0-0);	
}