#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		string S;
		int k;

		cin>>S;
		cin>>k;

		int A[256];
		memset(A,0,sizeof(A));

		for(int i=0;i<S.size();i++)
			A[S[i]]++;

		int mn = S.size();
		int n = 256;
		for(int i=0;i<n;i++)
			if(A[i])
				mn = min(mn,A[i]);

		int mx = mn + k;
		int sum = 0;
		for(int i=0;i<n;i++)
			if(A[i]>mx)
				sum += A[i]-mx;

		printf("%d\n",sum);
	}
}