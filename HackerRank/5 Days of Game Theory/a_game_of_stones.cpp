#include <bits/stdc++.h>

using namespace std;

int main()
{
	int A[105];
	memset(A,0,sizeof(A));

	A[0] = A[1] = 0;
	A[2] = A[3] = A[4] = A[5] = 1;

	for(int i=6;i<=100;i++)
		A[i] = !(A[i-2] && A[i-3] && A[i-5]);

	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;

		if(A[n])
			printf("First\n");
		else
			printf("Second\n");
	}
}