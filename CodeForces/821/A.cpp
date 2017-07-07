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

	int A[n][n];

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> A[i][j];

	int f = 1;
	for(int i=0; i<n and f; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(A[i][j] != 1)
			{
				int t = 0;
				for(int x=0; x<n and !t; x++)
				{
					for(int y=0; y<n; y++)
						if(A[i][x] + A[y][j] == A[i][j])
						{
							t = 1;
							break;
						}
				}

				f &= t;
			}
		}
	}

	if(f)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return (0-0);	
}