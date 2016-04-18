#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;

		int L[n];
		int R[n];

		for(int i=0;i<n;i++)
			cin>>L[i];

		for(int i=0;i<n;i++)
			cin>>R[i];

		int x = 0;

		for(int i=0;i<n;i++)
		{
			if(L[i]*R[i] > L[x]*R[x])
				x = i;
			else if(L[i]*R[i] == L[x]*R[x])
				if(R[i] > R[x])
					x = i;
		}

		cout<<x+1<<endl;
	}
}