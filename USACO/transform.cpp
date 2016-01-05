/*
iD: nikhil14
PROG: transform
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

vector < vector<char> > A;
vector < vector<char> > B;

void rotate()
{
	int i,j;
	char X[A.size()][A.size()];
	for(i=0;i<A.size();i++)
		for(j=0;j<A[i].size();j++)
			X[i][j] = A[i][j];
	for(i=0;i<A.size();i++)
		for(j=0;j<A[i].size();j++)
			A[j][A.size()-i-1] = X[i][j];
}

void reflect()
{
	for(int i=0;i<A.size();i++)
		for(int j=0;j<A[i].size()/2;j++)
			swap(A[i][j],A[i][A.size()-j-1]);
}

int main()
{
	bool oj = true;
	if(oj)
	{
		freopen("transform.in","r",stdin);
		freopen("transform.out","w",stdout);
	}
	int n,i,j;
	cin>>n;
	A.resize(n);
	for(i=0;i<n;i++)
	{
		A[i].resize(n);
		for(j=0;j<n;j++)
			cin>>A[i][j];
	}
	B.resize(n);
	for(i=0;i<n;i++)
	{
		B[i].resize(n);
		for(j=0;j<n;j++)
			cin>>B[i][j];
	}
	for(i=0;i<3;i++)
	{
		rotate();
		if(A==B)
		{
			cout<<i+1<<endl;
			return 0;
		}
	}
	rotate();
	reflect();
	if(A==B)
	{
		cout<<4<<endl;
		return 0;
	}
	for(i=0;i<4;i++)
	{
		rotate();
		if(A==B)
		{
			cout<<5<<endl;
			return 0;
		}
	}
	reflect();
	if(A==B)
	{
		cout<<6<<endl;
		return 0;
	}
	cout<<7<<endl;
}