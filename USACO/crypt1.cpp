/*
ID: nikhil14
PROG: crypt1
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

vector <int> V(10,0);

int makenum(int a, int b, int c)
{
	return (((a*10)+b)*10+c);
}

int check(int n)
{
	bool res = true;
	while(n)
	{
		res = res && (bool)V[n%10];
		n /= 10;
	}
	return res;
}

int main()
{
	freopen("crypt1.in","r",stdin);
	freopen("crypt1.out","w",stdout);

	int n;
	cin>>n;
	vector <int> A(n);
	for(int i=0;i<n;i++)
		cin>>A[i];
	for(int i=0;i<n;i++)
		V[A[i]] = 1;
	vector <int> X;
	vector <int> Y;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
				X.push_back(makenum(A[i],A[j],A[k]));
			Y.push_back(makenum(0,A[i],A[j]));
		}
	}
	int count = 0;
	for(int i=0;i<X.size();i++)
	{
		for(int j=0;j<Y.size();j++)
		{
			if(X[i]*(Y[j]%10)<1000 && X[i]*(Y[j]/10)<1000 && X[i]*Y[j]<10000 && check(X[i]*(Y[j]%10)) && check(X[i]*(Y[j]/10)) && check(X[i]*Y[j]))
				count++;
		}
	}
	cout<<count<<endl;
}