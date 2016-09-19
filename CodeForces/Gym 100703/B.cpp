#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;

	int A[n];
	for(int i=0;i<n;i++)
		cin>>A[i];

	int N = 1e5 + 5;
	int R[N],L[N];
	memset(R,0,sizeof(R));
	memset(L,0,sizeof(L));

	int k = 0;
	for(int i=1;i<N;i++)
	{
		R[i] = R[i-1];
		L[i] = L[i-1];
		if(k < n)
			L[i] += m;

		while(A[k] <= L[i] && k < n)
		{
			R[i]++;
			L[i] -= A[k];
			k++;
		}
		
	}

	int q;
	cin>>q;

	while(q--)
	{
		int x;
		cin>>x;

		printf("%d %d\n",R[x],L[x]);
	}
}