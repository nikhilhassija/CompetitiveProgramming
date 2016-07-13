#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;

		string S;
		cin>>S;

		for(int i=0;i<n;i++)
			S[i] -= '0';

		int X[n];
		for(int i=0;i<n;i++)
			cin>>X[i];

		vector < pair <int,int> > A(n);
		for(int i=0;i<n;i++)
		{
			A[i].first  = X[i];
			A[i].second = S[i];
		} 

		sort(A.begin(),A.end());

		vector <int> E;
		for(int i=0;i<n;i++)
			if(A[i].second)
				E.push_back(i);

		long long int sum = 0;
		if(E[0] != 0)
			sum += A[E[0]].first - A[0].first;

		for(int i=0;i<E.size()-1;i++)
		{
			long long int temp = A[E[i+1]].first - A[E[i]].first;
			long long int dist = temp;
			for(int j=E[i];j<E[i+1];j++)
			{
				temp = min(temp,dist-(A[j+1].first-A[j].first));
			}	

			sum += temp;
		}

		if(E[E.size()-1] != n-1)
			sum += A[n-1].first - A[E[E.size()-1]].first;
			
		printf("%lld\n",sum);
	}
}