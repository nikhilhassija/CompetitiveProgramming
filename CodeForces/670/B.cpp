#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;

	int A[n];
	for(int i=0;i<n;i++)
		cin>>A[i];

	for(int i=0;i<n;i++)
	{
		if(k>i)
			k -= i;
		else
			break;
	}

	cout<<A[k-1]<<endl;
}