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

		int A[n][6];
		memset(A,0,sizeof(A));

		int S[n];

		for(int i=0;i<n;i++)
		{
			cin>>S[i];
			for(int j=0;j<S[i];j++)
			{
				int x;
				cin>>x;
				A[i][x-1]++;
			}
		}

		for(int i=0;i<n;i++)
			sort(A[i],A[i]+6);

		for(int i=0;i<n;i++)
		{
			int a = A[i][0];
			int b = A[i][1] - A[i][0];
			int c = A[i][2] - A[i][1];

			S[i] += a*4 + b*2 + c;
		}

		int m = *max_element(S,S+n);
		int mc = 0;
		for(int i=0;i<n;i++)
			if(S[i] == m)
				mc++;

		if(mc == 1)
		{	
			int x;
			for(int i=0;i<n;i++)
				if(m == S[i])
					x = i;
			
			if(x)
				printf("%d\n",x+1);
			else
				printf("chef\n");
		}
		else
			printf("tie\n");
	}
}