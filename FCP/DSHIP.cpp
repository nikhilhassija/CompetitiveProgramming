#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int t,f;
	string S;
	vector <int> A;
	cin>>t;
	while(t--)
	{
		A.clear();
		A.resize(26,0);
		cin>>S;
		for(int i=0;i<S.size();i++)
			A[S[i]-'a']++;
		cin>>S;
		for(int i=0;i<S.size();i++)
			A[S[i]-'a']--;
		f = 0;
		for(int i=0;i<26;i++)
		{
			if(A[i])
			{
				f = 1;
				break;	
			}
		}
		if(f)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}