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

		int cur = 1;
		int ans = 1;

		for(int i=0; i<S.size()	; i++)
		{
			if(S[i] == '<')
			{
				cur++;
				ans = max(cur, ans);
			}
			else if(S[i] == '>')
			{
				cur = 1;
			}
		}

		cout << ans << endl;
	}

	return (0-0);	
}