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
	int t;
	cin >> t;

	while(t--)
	{
		string S;
		cin >> S;

		int ans = 0;
		int n = S.size();

		for(int i = 0; i < n; i++)
		{
			int len = 0;
			for(int j = i+1; S[i] == '1' and j < n; j++)
			{
				if(S[j] == '0')
					len++;
				else
				{
					if(S[j] == '1' and len)
						ans++;
					break;
				}
			}
		}

		cout << ans << endl;
	}

	return (0-0);	
}