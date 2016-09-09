#include <bits/stdc++.h>

#define scan(x) scanf("%d",&x)

using namespace std;

int main()
{
	int n;
	scan(n);

	int A[n];
	for(int i=0;i<n;i++)
		scan(A[i]);

	int X[n+1];
	X[0] = 0;
	for(int i=1;i<=n;i++)
		X[i] = A[i-1] ^ X[i-1];

	set <int> S;
	int EX[n+1];
	EX[0] = 0;
	for(int i=1;i<=n;i++)
	{
		EX[i] = EX[i-1];
		if(S.find(A[i-1]) == S.end())
		{
			S.insert(A[i-1]);
			EX[i] ^= A[i-1];
		}
	}

	int m;
	scan(m);

	printf("X\n");
	for(int i=1;i<=n;i++)
		printf("%d ",X[i]);

	printf("\nEX\n");
	for(int i=1;i<=n;i++)
		printf("%d ",EX[i]);
	printf("\n");
	
	while(m--)
	{
		int l,r;
		scan(l);
		scan(r);

		int ans = (X[r]^X[l-1]) ^ (EX[r] ^ EX[l-1]);

		printf("%d\n",ans);
	}
}