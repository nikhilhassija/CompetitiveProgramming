#include <bits/stdc++.h>

#define pss pair<string,string>

using namespace std;

bool comp(pss a, pss b)
{
	if(a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

int main()
{
	int n;
	cin>>n;

	vector <pss> A(n);
	for(int i=0;i<n;i++)
		cin>>A[i].second>>A[i].first;

	sort(A.begin(),A.end(),comp);

	for(int i=0;i<n;i++)
		cout<<A[i].second<<" "<<A[i].first<<endl;
}