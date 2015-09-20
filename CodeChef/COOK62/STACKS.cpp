#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int t,n,x;
	vector <int> S;
	cin>>t;
	while(t--)
	{
		S.clear();
		cin>>n;
		while(n--)
		{
			cin>>x;
			vector<int>::iterator it = upper_bound(S.begin(),S.end(),x);
			if(it != S.end())
				*it = x;
			else
				S.push_back(x);
		}
		cout<<S.size()<<' ';
		for(int i=0;i<S.size();i++)
			cout<<S[i]<<' ';
		cout<<endl;
	}
	return 0;
}