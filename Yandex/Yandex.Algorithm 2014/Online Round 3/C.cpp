#include <bits/stdc++.h>

#define lli long long int

using namespace std;

int main()
{
	lli n,d;
	cin>>n>>d;

	lli A[n];
	for(lli i=0;i<n;i++)
		cin>>A[i];

	map <lli,lli> M;
	lli C[n];
	memset(C,0,sizeof(C));

	C[0] = 0;
	M[A[0]] = 0;

	lli sum = 0;
	lli last = 0;

	for(lli i=0;i<n;i++)
	{
		lli a = 0ll, b = 0ll;

		if(M.find(A[i]-d) != M.end())
			a = M[A[i]-d];

		if(M.find(A[i]+d) != M.end())
			b = M[A[i]+d];

		lli x = max(last,max(a,b));
		last = max(last,x);

		sum += x;

		M[A[i]] = i+1;
	}

	cout<<sum<<endl;
}