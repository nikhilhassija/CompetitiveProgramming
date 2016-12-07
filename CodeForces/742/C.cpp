#include <bits/stdc++.h>

#define lli long long int 

using namespace std;

int main()
{
	int n;
	cin >> n;

	int C[n];
	for(int i=0;i<n;i++)
		cin >> C[i];

	for(int i=0;i<n;i++)
		C[i]--;

	int V[n];
	memset(V, 0, sizeof(V));

	vector <lli> L;

	for(int i=0;i<n;i++)
	{
		if(V[i] == 0)
		{
			int s = i;
			lli l = 1;

			int x = C[i];

			while(x != i)
			{
				if(V[x] == 1)
				{
					printf("-1\n");
					return 0;
				}

				V[x] = 1;
				x = C[x];
				l++;
			}

			L.push_back(l);
		}
	}

	lli ans = 1;
	int div2 = 1;
	int divo = 1;
	for(int i=0;i<L.size();i++)
	{
		if(L[i] % 2 == 0)
			L[i] /= 2;

		ans = ans*(L[i]/__gcd(ans, L[i]));
	}


	cout << ans << endl;
}