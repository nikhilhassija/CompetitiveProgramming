#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,q;
	cin >> n >> q;

	int A[n];
	for(int i=0;i<n;i++)
		cin >> A[i];

	while(q--)
	{
		int t,l,r,e;

		cin >> t >> l >> r;

		l--;
		r--;

		if(t)
		{
			int c = 0;

			for(int i=l;i<=r;i++)
				c += A[i] <= 0;
		}
		else
		{
			cin >> e;
			for(int i=l;i<=r;i++)
				A[i] -= e;
		}
	}
}