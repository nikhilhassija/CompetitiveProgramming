#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;

	int A[n+5];
	memset(A,0,sizeof(A));

	for(int i=0;pow(i,3)<=n;i++)
		for(int j=i;pow(i,3)+pow(j,3)<=n;j++)
			A[int(pow(i,3)+pow(j,3))]++;

	for(int i=1;i<=n;i++)
		if(A[i] > 1)
			cout<<i<<endl;
}