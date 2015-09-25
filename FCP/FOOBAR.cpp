#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int t,i;
	string S;
	vector <int> A;
	cin>>t;
	while(t--)
	{
		A.clear();
		A.resize(26,0);
		cin>>S;
		for(i=0;i<S.size();i++)
			A[S[i]-'a']++;
		cout<<min(A['f'-'a'],min(A['o'-'a']/2,min(A['b'-'a'],min(A['a'-'a'],A['r'-'a']))))<<endl;
	}
	return 0;
}