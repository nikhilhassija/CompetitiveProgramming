#include <bits/stdc++.h>

#define lli long long int 

using namespace std;

const int N = 1e7 + 5; 
vector <lli> A(N);

int main()
{
	lli n,x,y;
	cin>>n>>x>>y;

	for(int i=0;i<=n;i++)
		A[i+1] = 1e18; 

	A[0] = 0;
	for(lli i=0;i<=n;i++)
	{
		A[i] = min(A[i],A[i+1]+x);
		A[i+1] = min(A[i+1],A[i]+x);
		if(2*i <= n+3)
			A[2*i] = min(A[2*i],A[i]+y); 
	}

	printf("%lld\n",A[n]);
}