#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))

using namespace std;

int main()
{
	int n;
	cin >> n;

	string S;
	cin >> S;

	char h=0, v=0;

	int x = 1;
	for(int i=0;i<n;i++)
	{
		if(S[i] == 'L' || S[i] == 'R')
		{
			if(h)
			{
				if(S[i] != h)
				{
					h = S[i];
					v = 0;
					x++;
				}
			}
			else
				h = S[i];
		}

		if(S[i] == 'U' || S[i] == 'D')
		{
			if(v)
			{
				if(S[i] != v)
				{
					v = S[i];
					h = 0;
					x++;
				}
			}
		else
			v = S[i];
		}
	}

	cout << x << endl;
}