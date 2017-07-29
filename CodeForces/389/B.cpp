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

	string S[n];
	for(int i = 0; i < n; i++)
		cin >> S[i];

	for(int i = 1; i < n - 1; i++)
	{
		for(int j = 1; j < n - 1; j++)
		{
			if(	S[i][j] == '#' and 
				S[i-1][j] == '#' and
				S[i+1][j] == '#' and
				S[i][j+1] == '#' and
				S[i][j-1] == '#')
			{
				S[i][j] = '.';
				S[i-1][j] = '.';
				S[i+1][j] = '.';
				S[i][j+1] = '.';
				S[i][j-1] = '.';
			}
		}
	}



	for(int i = 0; i < n; i++)
		for(int  j = 0; j < n; j++)
			if(S[i][j] == '#')
			{
				cout << "NO" << endl;
				return 0;
			}

	cout << "YES" << endl;

	return (0-0);	
}