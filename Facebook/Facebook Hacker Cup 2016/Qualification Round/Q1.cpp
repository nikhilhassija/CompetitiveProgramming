#include <bits/stdc++.h>

using namespace std;

long long int dist(long long int a,long long int b)
{
	return a*a + b*b;
}

long long int nc2(long long int a)
{
	return (a*(a-1))/2;
}

int main()
{
	int t;
	cin>>t;
	for(int c=1;c<=t;c++)
	{
		int n;
		cin>>n;
		vector <int> X(n);
		vector <int> Y(n);
		vector < vector<int> > A(n);
		for(int i=0;i<n;i++)
			A[i].resize(n);
		for(int i=0;i<n;i++)
			cin>>X[i]>>Y[i];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				A[i][j] = A[j][i] = dist(X[i]-X[j],Y[i]-Y[j]);
		long long int sum = 0;
		for(int i=0;i<n;i++)
		{
			sort(A[i].begin(),A[i].end());
			int count = 1;
			for(int j=1;j<n;j++)
			{
				if(A[i][j-1] == A[i][j])
					count++;
				else
				{
					sum += nc2(count);
					count = 1;
				}
			}
			sum += nc2(count);
		}
		printf("Case #%d: %lld\n",c,sum);
	}
}