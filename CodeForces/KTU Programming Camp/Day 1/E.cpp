#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int64_t n,i,j;
	cin>>n;
	int64_t A[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>A[i][j];
	int64_t sum=0,temp;
	for(i=0;i<n;i++)
		sum+= A[0][i];
	for(i=0;i<n;i++)
	{
		temp = 0;
		for(j=0;j<n;j++)
			temp += A[i][j];
		A[i][i] = sum - temp;
	}
	temp = 0;
	for(i=0;i<n;i++)
		temp += A[i][i];
	temp = (sum-temp)/(n-1);
	for(i=0;i<n;i++)
		A[i][i] += temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<A[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}