#include <bits/stdc++.h>

#define lli long long int

using namespace std;

int main()
{
	lli n,m;
	cin>>n>>m;

	lli R[n],C[n];
	memset(R,0,sizeof(R));
	memset(C,0,sizeof(C));

	lli r=0,c=0;
	lli ans = n*n;
	while(m--)
	{
		lli x,y;
		cin>>x>>y;

		x--;
		y--;

		if(R[x] && C[y])
		{
			ans -= 0;
		}
		else if(R[x] && C[y] == 0)
		{
			ans -= n;
			ans += r;

			C[y] = 1;
			c++;
		}
		else if(R[x] == 0 && C[y])
		{
			ans -= n;
			ans += c;

			R[x] = 1;
			r++;
		}
		else
		{
			ans -= 2*n;
			ans += r + c + 1;

			R[x] = 1;
			C[y] = 1;
			r++;
			c++;
		}

		cout<<ans<<' ';
	}
	printf("\n");
}