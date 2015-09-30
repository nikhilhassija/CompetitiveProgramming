#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t,x,i,m,s;
	vector <int> A;
	string S;
	cin>>t;
	while(t--)
	{
		cin>>S;
		A.clear();
		A.resize(26,0);
		for(i=0;i<S.size();i++)
			A[S[i]-'a']++;
		m = 0;
		s = 0;
		for(i=0;i<A.size();i++)
		{
			if(A[m]<A[i])
				m = i;
			s += A[i];
		}
		s -= A[m];
		if(A[m]>s)
			cout<<(char)(m+'a')<<endl;
		else
			cout<<"-1"<<endl;
	}
}