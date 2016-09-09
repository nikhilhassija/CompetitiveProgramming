#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;

	long long int F[n+1];
	F[0] = 1;
	for(int i=0;i<n;i++)
		F[i+1] = (i+1)*F[i];

	int A[n];
	for(int i=0;i<n;i++)
		cin>>A[i];

	int C[101];
	memset(C,0,sizeof(C));
	for(int i=0;i<n;i++)
		C[A[i]]++;

	long double N = F[n];
	long double r = 1;
	for(int i=0;i<101;i++)
		r *= F[C[i]];

	long double ans = (N/r);

	printf("%.6Lf\n",ans);
}