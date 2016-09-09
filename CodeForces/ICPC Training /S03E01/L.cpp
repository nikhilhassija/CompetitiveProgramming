#include <bits/stdc++.h>

using namespace std;

int main()
{
	string S;
	cin>>S;

	int n = S.size();
	for(int i=0;i<n;i++)
		S[i] -= '0';

	int z = 0;
	for(int i=0;i<n;i++)
		if(S[i] == 0)
			z++;

	vector <int> A,B;
	for(int i=0;i<z;i++)
		if(S[i])
			A.push_back(i);

	for(int i=z;i<n;i++)
		if(S[i] == 0)
			B.push_back(i);

	n = A.size();
	for(int i=0;i<n;i++)
		printf("%d ",A[i]);

	for(int i=0;i<n;i++)
		printf("%d ",B[i]);

	long double DP[n][n];
	for(int i=0;i<n;i++)
		DP[i][0] = sqrt(abs(A[i] - B[0]));

	for(int i=1;i<n;i++)
		DP[0][i] = min(DP[0][i-1],(long double)sqrt(abs(A[0]-B[i])));

	for(int i=1;i<n;i++)
		for(int j=1;j<n;j++)
			DP[i][j] = min(DP[i][j-1],DP[i-1][j-1])+(long double)sqrt(abs(A[i]-B[j]));

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%Lf ",DP[i][j]);
		printf("\n");
	}

	printf("%.12Lf\n",DP[n-1][n-1]);
}