/*
ID: nikhil14
PROG: milk2
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

bool oj = true;

int ismergeable(pair <int,int> a, pair<int,int> b)
{
	return (a.first<=b.first) && (b.first<=a.second);
}

int main()
{
	if(oj)
	{
		freopen("milk2.in","r",stdin);
		freopen("milk2.out","w",stdout);
	}
	int n,i,j;
	cin>>n;
	vector < pair<int,int> > A(n);
	for(i=0;i<n;i++)
		cin>>A[i].first>>A[i].second;
	sort(A.begin(),A.end());
	for(i=0;i<n;i++)
	{
		if(A[i].first == A[i].second)
			continue;
		for(j=i+1;j<n;j++)
		{
			if(ismergeable(A[i],A[j]) || ismergeable(A[j],A[i]))
			{
				A[i].first = min(A[i].first,A[j].first);
				A[i].second = max(A[i].second,A[j].second);
				A[j].first = 0;
				A[j].second = 0;
			}
		}
	}
	sort(A.begin(),A.end());
	for(i=0;i<n;i++)
		if(A[i].first != A[i].second)
			break;
	int milk = 0;
	int idle = 0;
	for(;i<n-1;i++)
	{
		milk = max(milk,A[i].second-A[i].first);
		idle = max(idle,A[i+1].first-A[i].second);
	}
	milk = max(milk,A[i].second-A[i].first);
	cout<<milk<<" "<<idle<<endl;  
}	