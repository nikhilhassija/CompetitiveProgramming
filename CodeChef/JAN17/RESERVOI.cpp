#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))
#define fastio() ios_base::sync_with_stdio(0);

using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n,m;
		cin >> n >> m;

		string S[n];
		for(int i=0;i<n;i++)
			cin >> S[i];

		string T[n];
		for(int i=0;i<n;i++)
			T[i] = S[i];

		for(int i=0;i<n-1;i++)
			for(int j=0;j<n;j++)
				if(T[i][j] == 'B' && T[i+1][j] != 'B')
					swap(T[i][j], T[i+1][j]);

		int f = 0;
		for(int i=0;i<n;i++)
			if(T[i] != S[i])
				f = 1;

		if(f)
		{
			printf("no\n");
		}
		else
		{
			for(int i=0;i<n-1;i++)
				for(int j=0;j<n;j++)
				{
					if(T[i][j] == 'W' && T[i+1][j] == 'A')
						T[i+1][j] = 'W';
					else if(j && (T[i][j] == 'W' && T[i][j-1] == 'A'))
						T[i][j-1] = 'W';
					else if(j && (T[i][j] == 'A' && T[i][j-1] == 'W'))
						T[i][j] = 'W';
				}

			int f = 0;
			for(int i=0;i<n;i++)
				if(T[i] != S[i])
					f = 1;

			if(f)
			{
				printf("no\n");
			}
			else
			{
				int f = 0;

				for(int i=0;i<n;i++)
					if(T[i][0] == 'W' || T[i][m-1] == 'W')
						f = 1;

				if(f)
					printf("no\n");
				else
					printf("yes\n");
			}
		}
	}	
}