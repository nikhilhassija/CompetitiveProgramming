#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;

	int A[n];
	for(int i=0;i<n;i++)
		cin>>A[i];

	int d = n;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(A[i] == A[j])
				d = min(j-i,d);

	if(d == n)
		d = -1;
	printf("%d\n",d);
}