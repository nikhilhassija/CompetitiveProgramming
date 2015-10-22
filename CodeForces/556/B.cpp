#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	vector <int> A(n,0);
	for(int i=0;i<n;i++)
		cin>>A[i];
	int d = n - A[0];
	for(int i=0;i<n;i++)
	{
		if(i%2)
			A[i] += n - d;
		else
			A[i] += d;
		A[i] %= n;
	}
	for(int i=0;i<n;i++)
	{
		if(A[i]!=i)
		{
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}