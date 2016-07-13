#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m,b,c;
	cin>>n>>m>>b>>c;

	for(int i=0;i<n*n;i++)
		cin>>c;

	int A[b];

	while(m--)
	{

		for(int i=0;i<b;i++)
			cin>>A[i]>>c;

		for(int i=0;i<b;i++)
			printf("%d\n",A[i]);
		fflush(stdout);
	}
}