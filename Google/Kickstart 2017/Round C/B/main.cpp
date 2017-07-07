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
	int T;
	cin >> T;

	for(int t=1; t<=T; t++)
	{
		int n;
		cin >> n;

		string S[n];
		for(int i=0; i<n; i++)
			cin >> S[i];		

		int f = 1;

		int one = 0;
		int two = 0;

		for(int i=0; i<n; i++)
		{
			int c = 0;
			for(int j=0; j<n; j++)
				c += (S[i][j] == 'X');

			one += (c == 1);
			two += (c == 2);
		}

		if(one != 1 or two != (n - 1))
			f = 0;

		one = 0;
		two = 0;

		for(int j=0; j<n; j++)
		{
			int c = 0;
			for(int i=0; i<n; i++)
				c += (S[i][j] == 'X');


			one += (c == 1);
			two += (c == 2);
		}

		if(one != 1 or two != (n - 1))
			f = 0;	

		cout << "Case #" << t << ": ";
		if(f)
			cout << "POSSIBLE" << endl;
		else
			cout << "IMPOSSIBLE" << endl;
	} 

	return (0-0);	
}