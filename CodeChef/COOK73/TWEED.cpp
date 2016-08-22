#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n;
		string S;
		cin>>n>>S;

		int A[n];
		for(int i=0;i<n;i++)
			cin>>A[i];

		int c = 0;
		for(int i=0;i<n;i++)
			c += A[i]%2;

		if(c)
			printf("Dum\n");
		else if(n == 1 && S == "Dee")
			printf("Dee\n");
		else
			printf("Dum\n");
	}
}