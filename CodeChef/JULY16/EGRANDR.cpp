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

		long long int A[n];
		for(int i=0;i<n;i++)
			cin>>A[i];

		long long int C[6];
		memset(C,0,sizeof(C));
		for(int i=0;i<n;i++)
			C[A[i]]++;

		if(C[5] && C[2] == 0)
		{
			long long int sum = 3*C[3] + 4*C[4] + 5*C[5];

			if(sum >= int(float(n*5)*0.8))
				printf("Yes\n");
			else
				printf("No\n");
		}
		else
			printf("No\n");
	}
}