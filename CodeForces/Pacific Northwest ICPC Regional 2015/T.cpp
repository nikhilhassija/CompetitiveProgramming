#include <bits/stdc++.h>

using namespace std;

int main()
{
	int A[3];
	for(int i=0;i<3;i++)
		cin>>A[i];

	int B[3];
	for(int i=0;i<3;i++)
		cin>>B[i];

	sort(A,A+3);
	sort(B,B+3);

	for(int i=0;i<3;i++)
		if(A[i] != B[i])
		{
			printf("NO\n");
			return 0;
		}

	if((A[0]*A[0]) + (A[1]*A[1]) == (A[2]*A[2]))
		printf("YES\n");
	else
		printf("NO\n");
}