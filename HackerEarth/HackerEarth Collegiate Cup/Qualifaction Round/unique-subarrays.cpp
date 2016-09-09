#include <bits/stdc++.h>

#define lli long long int

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		lli n;
		cin>>n;

		lli A[n];
		for(int i=0;i<n;i++)
			cin>>A[i];

		lli l = 0;
		lli a = 0;
		map <lli,lli> M;

		for(lli r=0;r<n;r++)
		{
			if(M.find(A[r]) != M.end())
				l = max(M[A[r]],l);

			lli x = (r-l)+1;
			a += (x*(x+1))/2;

			M[A[r]] = r+1;
		} 

		printf("%lld\n",a);
	}
}