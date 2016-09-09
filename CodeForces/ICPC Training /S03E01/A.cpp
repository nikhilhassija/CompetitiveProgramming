#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;

		int A[n],B[n];
		for(int i=0;i<n;i++)
			cin>>A[i];

		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;

			B[x] = i;
		}

		int l = 0;
		int m = 0;
		for(int i=0;i<n;i++)
		{
			m = max(m,B[A[i]]);

			if(m == i)
			{
				cout<<l+1<<'-'<<i+1<<' ';
				l = i+1;
				m = i+1;
			}
		}
		cout<<'\n';
	}
}