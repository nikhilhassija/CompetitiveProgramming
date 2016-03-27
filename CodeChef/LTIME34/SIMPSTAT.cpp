#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n,k;
		cin>>n>>k;

		vector <int> A(n);
		for(int i=0;i<n;i++)
			cin>>A[i];

		sort(A.begin(),A.end());

		n -= 2*k;

		double sum = 0;
		for(int i=0;i<n;i++)
			sum += A[i+k];

		sum /=n;

		printf("%.9f\n",sum);
	}
}