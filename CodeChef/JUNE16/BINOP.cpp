#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		string A,B;
		cin>>A>>B;

		int n = A.size();
		for(int i=0;i<n;i++)
		{
			A[i] -= '0';
			B[i] -= '0';
		}

		int C[2],R[2],I[2];
		memset(C,0,sizeof(C));
		memset(R,0,sizeof(R));
		memset(I,0,sizeof(I));

		for(int i=0;i<n;i++)
		{
			C[A[i]]++;
			R[B[i]]++;
			if(A[i] == B[i])
				I[A[i]]++;
		}

		int ans = 0;

		if(C[0] == 0 || C[1] == 0)
		{
			printf("Unlucky Chef\n");
		}
		else
		{
			if(R[0] > C[0])
			{
				int del = R[0] - C[0];
				ans  +=  del;
				C[0] += del;
				I[0] += del;
				C[1] -= del;
			}
			else
			{
				int del = R[1] - C[1];
				ans  += del;
				C[0] -= del;
				C[1] += del;
				I[1] += del;
			}

			int del = A.size() - (I[0]+I[1]);
			ans += del/2;

			printf("Lucky Chef\n%d\n",ans);
		}
	}
}