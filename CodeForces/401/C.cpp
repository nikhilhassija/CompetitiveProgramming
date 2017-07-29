#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	if (n-1 > m || m > 2*(n+1))
		cout<<"-1\n";
	else
	{
		while (n && m)
		{
			if (n > m)
			{
				--n; --m;
				cout<<"01";
			}
			else if (n == m)
			{
				--n; --m;
				cout<<"10";
			}
			else if (m > n)
			{
				m-=2; --n;
				cout<<"110";
			}
		}
		if (n)
		{
			for (int i = 0; i < n; ++i)
			{
				cout<<"0";
			}
		}
		else
		{
			for (int i = 0; i < m; ++i)
			{
				cout<<"1";
			}
		}
				cout<<endl;
	}
	return 0;
}