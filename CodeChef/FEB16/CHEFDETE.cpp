#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,x;
	cin>>n;

	vector <int> A(n,0);
	for(int i=0;i<n;i++)
	{
		cin>>x;
		if(x)
			A[x-1]++;
	}

	for(int i=0;i<n;i++)
		if(A[i]==0)
			cout<<i+1<<" ";
	cout<<endl;
}