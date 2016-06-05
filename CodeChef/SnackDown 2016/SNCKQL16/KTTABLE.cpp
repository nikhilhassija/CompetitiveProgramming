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

		int A[n+1];
		A[0] = 0;
		for(int i=1;i<=n;i++)
			cin>>A[i];

		int B[n+1];
		for(int i=1;i<=n;i++)
			cin>>B[i];

		int c = 0;
		for(int i=1;i<=n;i++)
			if(!(A[i]-A[i-1]<B[i]))
				c++;

		printf("%d\n",c);
	}
}