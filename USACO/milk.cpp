/*
ID: nikhil14
PROG: milk
LANG: C++11
*/

#include <bits/stdc++.h>

bool oj = true;

using namespace std;

int main()
{
	if(oj)
	{
		freopen("milk.in","r",stdin);
		freopen("milk.out","w",stdout);
	}
	long long int n,m;
	long long int x,y;
	long long int cost = 0;;
	vector < pair<long long int, long long int> > A;
	cin>>n>>m;	
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		A.push_back(make_pair(x,y));
	}
	sort(A.begin(),A.end());
	for(int i=0;i<m && n;i++)
	{
		cost += min(n,A[i].second)*A[i].first;
		n -= min(n,A[i].second);
	}
	cout<<cost<<endl;
}