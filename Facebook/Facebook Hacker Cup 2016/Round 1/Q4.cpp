#include <bits/stdc++.h>

using namespace std;

vector < vector <int> > A;
vector <int> d;

void work(int);

int candefeat(int,int);

int main()
{
	int t;
	cin>>t;
	for(int c=1;c<=t;c++)
	{
		printf("Case #%d:\n",c);
		int n;
		cin>>n;
		A.clear();
		A.resize(n);
		for(int i=0;i<n;i++)
			A[i].resize(n);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>A[i][j];
		if(n==1)
		{
			printf("1 1\n");
		}
		else
		{
			work(n);
		}
	}
}

void work(int n)
{
	int l = n/2 + 1;
	int b,w;
	for(int i=0;i<n;i++)
	{
		b = l;
		w = 1;
		d.clear();
		d.resize(n,0);
		d[i] = 1;
		for(int j=0;j<n;j++)
		{
			if(A[i][j] == 0 && i!=j)
				w = l;
		} 
		b = ((b-1)>>(candefeat(i,0))) + 1;
		if(b==0)
			b = 1;
		printf("%d %d\n",b,w);
	}
}

int candefeat(int x, int l)
{
	d[x] = 1;
	int c = l;
	for(int i=0;i<A[x].size();i++)
	{
		if(A[x][i] && d[i] == 0)
		{
			l = max(l,c+candefeat(i,l+1));
		}
	}
	d[x] = 0;
	return l;
}