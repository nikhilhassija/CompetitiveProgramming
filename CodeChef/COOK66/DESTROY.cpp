#include <bits/stdc++.h>

using namespace std;

int mod(int x)
{
	return (x<0)?(-x):x;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector <int> X(n);
		for(int i=0;i<n;i++)
			cin>>X[i];
		int count = 1;
		sort(X.begin(),X.end());
		vector <int> A;
		for(int i=1;i<n;i++)
		{
			if(X[i] == X[i-1])
				count++;
			else
			{
				A.push_back(count);
				count = 1;
			}
		}
		A.push_back(count);
		sort(A.rbegin(),A.rend());
		n = n/2 + (n%2);
		cout<<max(n,A[0])<<endl;
	}
}