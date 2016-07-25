#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;

	int A[n];
	for(int i=0;i<n;i++)
		cin>>A[i];

	int sum = 0;
	for(int i=0;i<n;i++)
		sum += A[i];

	int x = (sum*2)/n;

	int C[n];
	memset(C,0,sizeof(C));
	for(int i=0;i<n;i++)
	{
		if(C[i] == 0)
		{
			printf("%d ",i+1);
			C[i] = 1;
			for(int j=0;j<n;j++)
			{
				if(C[j] == 0 && (x-A[j]) == A[i])
				{
					C[j] = 1;
					printf("%d\n",j+1);
					break;
				}
			}
		}
	}


}