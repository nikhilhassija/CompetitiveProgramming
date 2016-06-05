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

		int A[n];
		for(int i=0;i<n;i++)
			cin>>A[i];

		int f=1;
		for(int i=1;i<n-1 && f;i++)
			if(A[i] == A[i-1] && A[i+1] == A[i])
				f = 0;

		if(f)
			printf("No\n");
		else
			printf("Yes\n");
	}
}