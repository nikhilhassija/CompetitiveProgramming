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

		int c = 0;
		for(int i=0;i<n;i++)
		{
			for(int j=i;j<n;j++)
			{
				int sum = 0;
				int prod = 1;
				for(int k=i;k<=j;k++)
				{
					sum += A[k];
					prod *= A[k];
				}

				// printf("%d %d == %d = %d || %d \n",i,j,prod,sum,prod==sum);

				if(prod == sum)
					c++;
			}
		}
		printf("%d\n",c);
	}
}