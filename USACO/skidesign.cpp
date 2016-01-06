/*
ID: nikhil14
PROG: skidesign
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

int mod(int x)
{
	if(x<0) x=-x;
	return x;
}

int inrange(int a, int b, int c)
{
	return (a<=b) && (b<=c);
}

int main()
{
	freopen("skidesign.in","r",stdin);
	freopen("skidesign.out","w",stdout);
	int n,i;
	cin>>n;
	int A[n];
	for(i=0;i<n;i++)
		cin>>A[i];
	int m = 1e7;
	for(i=0;i<100;i++)
	{
		int cost = 0;
		for(int j=0;j<n;j++)
			if(!inrange(i,A[j],i+17))
				cost += min(mod(A[j]-i),mod(i+17-A[j]))*min(mod(A[j]-i),mod(i+17-A[j]));
		m = min(m,cost);
	}
	cout<<m<<endl;
}