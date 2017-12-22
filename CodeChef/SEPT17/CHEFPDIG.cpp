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
	int t;
	cin >> t;

	while (t--)
	{
		string S;
		cin >> S;

		int A[10];
		mset(A);

		for (char s: S)
			A[s - '0']++;

		for (int i = 'A'; i <= 'Z'; i++)
		{
			int x = i / 10;
			int y = i % 10;

			if (A[x])
			{
				A[x]--;

				if (A[y])
					cout << (char) i;

				A[x]++;
			}
		}

		cout << endl;
	}	
	
	return (0-0);	
}