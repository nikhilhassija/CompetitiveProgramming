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
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;

	while(t--)
	{
		string S;
		cin >> S;

		int n = S.size();

		if((S[n-2] == 'c' and S[n-1] == 'h') 
			or S[n-1] == 'x' 
			or S[n-1] == 's' 
			or S[n-1] == 'o')
		{
			S = S + "es";
		}
		else if((S[n-1] == 'f'))
		{
			S[n-1] = 'v';
			S = S + "es";
		}
		else if(S[n-2] == 'f' and S[n-1] == 'e')
		{
			S[n-2] = 'v';
			S = S + "s";
		}
		else if(S[n-1] == 'y')
		{
			S[n-1] = 'i';
			S = S + "es";
		}
		else
			S = S + "s";

		cout << S << endl;
	}
	return (0-0);	
}