#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,a,b,c,d;
	cin>>n>>a>>b>>c>>d;

	long long int ans = 0;

	for(int i=4;i<=4*n;i++)
	{
		int D[4];
		D[0] = i - a - b;
		D[1] = i - a - c;
		D[2] = i - d - b;
		D[3] = i - d - c;

		int dm = min(min(D[0],D[1]),min(D[2],D[3]));
		int dM = max(max(D[0],D[1]),max(D[2],D[3]));


		// printf("%d --> %d %d %d %d \n",i,D[0],D[1],D[2],D[3]);
		if(dm > 1 && dM <= 2*n)
		{
			int m[4],M[4];

			for(int i=0;i<4;i++)
			{
				m[i] = max(1,D[i]-n);
				M[i] = min(n,D[i]-1);
			}

			int am = 0;
			int aM = n;
			for(int i=0;i<4;i++)
			{
				am = max(am,m[i]);
				aM = min(aM,M[i]);
			}

			if(aM >= am)
				ans += aM - am + 1;
		}
	}

	cout<<ans<<endl;
}