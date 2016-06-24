#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1005 

int A[MAX_N][MAX_N];
int S[MAX_N][MAX_N];
int M[MAX_N][MAX_N];
int n,m;

int build(int, int);
int query(int, int);
int sum(int, int, int, int);

int main()
{
	scanf("%d %d",&n,&m);

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&A[i][j]);

	build(n,m);

	int q;
	scanf("%d",&q);

	while(q--)
	{
		int a,b;
		scanf("%d %d",&a,&b);

		printf("%d\n",query(a,b));
	}
}

int build(int n, int m)
{
	memset(S,0,sizeof(S));
	for(int i=1;i<=n;i++)
	{
		S[i][1] = A[i-1][0];
		for(int j=2;j<=m;j++)
			S[i][j] = S[i][j-1] + A[i-1][j-1];
	}
 
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			S[i][j] += S[i-1][j];
	}

}
 
int sum(int xl, int xr, int yl, int yr)
{
	return S[xr][yr] + S[xl-1][yl-1] - S[xl-1][yr] - S[xr][yl-1];
}

int query(int a, int b)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			M[i][j] = A[i][j];

	for(int i=0;i<n;i++)
	{
		deque <int> Q;

		for(int j=0;j<b;j++)
		{
			while((!Q.empty()) && M[i][j] >= M[i][Q.back()])
				Q.pop_back();

			Q.push_back(j);
		}

		for(int j=b;j<m;j++)
		{
			M[i][j-b] = M[i][Q.front()];
			while((!Q.empty()) && Q.front() <= j-b)
				Q.pop_front();

			while((!Q.empty()) && M[i][j] >= M[i][Q.back()])
				Q.pop_back();

			Q.push_back(j);
		}

		M[i][m-b] = M[i][Q.front()];
	}		


	for(int j=0;j<(m-b+1);j++)
	{
		deque <int> Q;

		for(int i=0;i<a;i++)
		{
			while((!Q.empty()) && M[i][j] >= M[Q.back()][j])
				Q.pop_back();

			Q.push_back(i);
		}

		for(int i=a;i<n;i++)
		{
			M[i-a][j] = M[Q.front()][j];
			while((!Q.empty()) && Q.front() <= i-a)
				Q.pop_front();

			while((!Q.empty()) && M[i][j] >= M[Q.back()][j])
				Q.pop_back();

			Q.push_back(i);
		}

		M[n-a][j] = M[Q.front()][j];
	}

	for(int i=0;i<(n-a+1);i++)
		for(int j=0;j<(m-b+1);j++)
			M[i][j] = (M[i][j]*a*b) - sum(i+1,i+a,j+1,j+b);

	int ans = M[0][0];

	for(int i=0;i<(n-a+1);i++)
		for(int j=0;j<(m-b+1);j++)
			ans = min(ans,M[i][j]);

	return ans;
}