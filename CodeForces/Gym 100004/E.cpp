#include <bits/stdc++.h>

using namespace std;

int main()
{
	int z;
	cin >> z;

	while(z--)
	{
		int c,t,l;
		cin >> c >> t >> l;

		int E[c][t];
		int P[c][t];

		for(int i=0;i<c;i++)
			for(int j=0;j<t;j++)
				cin >> P[i][j] >> E[i][j];

		for(int i=0;i<t;i++)
			E[0][i] += P[0][i];

		for(int i=1;i<c;i++)
		{
			for(int j=0;j<t;j++)
			{
				int m = INT_MAX;

				for(int k=0;k<t;k++)
					m = min(m,E[i-1][k] + abs(P[i][j] - P[i-1][k]));

				E[i][j] += m;
			}
		}

		int m = INT_MAX;
		for(int i=0;i<t;i++)
			m = min(m,E[c-1][i] + abs(l-P[c-1][i]));

		printf("%d\n",m);
	}
}