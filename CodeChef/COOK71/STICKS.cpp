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

		int C[1005];
		memset(C,0,sizeof(C));
		for(int i=0;i<n;i++)
			C[A[i]]++;

		int a = 0;
		for(int i=1004;i>0;i--)
			if(C[i] > 1)
			{
				a = i;
				C[i] -= 2;
				break;
			}

		int b = 0;
		for(int i=1004;i>0;i--)
			if(C[i] > 1)
			{
				b = i;
				C[i] -= 2;
				break;
			}

		if(a && b)
			printf("%d\n",a*b);
		else
			printf("-1\n");
	}
}