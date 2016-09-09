#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 6e2 + 5;
int V[4][MAX_N];

set <string> S;

void visit(int, int, string, int, int);

int main()
{
	int p;
	cin>>p;

	while(p--)
	{
		int n;
		cin>>n;

		S.clear();

		char A[2][n+5];
		scanf("%s",A[0]);
		scanf("%s",A[1]);

		memset(V,0,sizeof(V));
		for(int i=0;i<MAX_N;i++)
			V[0][i] = V[3][i] = 1;

		V[1][0] = V[2][0] = V[1][n+1] = V[2][n+1] = 1;

		for(int i=0;i<n;i++)
		{
			visit(1,i+1,(string)"",0,n);
			visit(2,i+1,(string)"",0,n);
		}
	}
}