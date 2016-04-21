#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n,q;
		cin>>n>>q;

		string S;
		cin>>S;

		int A[257];
		memset(A,0,sizeof(A));

		for(int i=0;i<n;i++)
			A[S[i]]++;

		while(q--)
		{
			char c;
			string Q;

			cin>>c;
			cin>>Q;

			if(Q == "even")
			{
				if(A[c]%2)
					printf("no\n");
				else
					printf("yes\n");
			}
			else
			{
				if(A[c]%2)
					printf("yes\n");
				else
					printf("no\n");
			}
		}
	}
}