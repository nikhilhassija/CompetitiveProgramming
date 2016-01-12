#include <bits/stdc++.h>

using namespace std;

vector < string > S;
vector < vector < pair <long int,long int> > >  A;
vector < int > B;

long long int diff(string x, string y)
{
	long long int i;
	for(i=0;i<x.size() && i<y.size();i++)
		if(x[i]!=y[i])
			break;
	return (x.size()-i)+(y.size()-i);
}

long long int work(int x, int k)
{
	B[x] = 1;
	// cout<<S[x]<<endl;`
	if(k == 1)
	{
		long long int m = 1e9;
		for(int i=0;i<A[x].size();i++)
			if(B[A[x][i].second] == 0)
				m = min(m,A[x][i].first+(long long int)S[A[x][i].second].size());
		return m;
	}
	else
	{
		long long int res = 0;
		for(int i=0;i<A[x].size();i++)
			if(B[A[x][i].second] == 0)
			{
				res = A[x][i].first + work(A[x][i].second,k-1);
				break;
			}
		return res;
	}
}

int main()
{
	int t;
	cin>>t;
	for(int c=1;c<=t;c++)
	{
		A.clear();
		S.clear();
		B.clear();
		long long int n,k;
		cin>>n>>k;
		S.resize(n);
		A.resize(n);
		for(int i=0;i<n;i++)
			cin>>S[i];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				A[i].push_back(make_pair(diff(S[i],S[j]),j));
			sort(A[i].begin(),A[i].end());
		}
		long long int M[n];
		if(k>1)
		{
			for(int i=0;i<n;i++)
			{
				B.clear();
				B.resize(n,0);
				M[i] = S[i].size() + work(i,k-1);
			}
		}
		else
		{
			for(int i=0;i<n;i++)
				M[i] = (2*S[i].size());
		}	
		long long int m = M[0];
		for(int i=0;i<n;i++)
			m = min(m,M[i]);
		m += k;
		printf("Case #%d: %lld\n",c,m);
	}
}