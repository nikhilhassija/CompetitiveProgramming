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

	int a=0,b=0;
	for(int i=0;i<3;i++)
	{
		if(A[i] > B[i])
			a++;
		if(B[i] > A[i])
			b++;
	}	

	printf("%d %d\n",a,b);
}