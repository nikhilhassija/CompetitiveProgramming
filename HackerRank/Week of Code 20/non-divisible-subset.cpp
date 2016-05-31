#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;

	int A[k];
	memset(A,0,sizeof(A));
	while(n--)
	{
		int x;
		cin>>x;
		A[x%k]++;
	}

	int s = 0;
	if(A[0])
		s++;
	if(k%2 == 0 && A[k/2])
		s++;

	for(int i=1;i<=(k/2 - ((k+1)%2));i++)
		s += max(A[i],A[k-i]);

	cout<<s<<endl;
}