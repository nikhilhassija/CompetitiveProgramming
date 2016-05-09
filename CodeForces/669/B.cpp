#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;

	string S;
	cin>>S;

	vector <int> A(n);
	for(int i=0;i<n;i++)
	{
		A[i] = 1;
		if(S[i] == '<')
			A[i] *= -1;
	}

	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		A[i] *= x;
	}

	int V[n];
	memset(V,0,sizeof(V));

	int x = 0;

	while(1)
	{
		if(x<0 || x>=n)
			break;
		if(V[x])
		{
			printf("INFINITE\n");
			return 0;
		}
		V[x] = 1;
		x += A[x];
	}

	printf("FINITE\n");
	return 0;
}