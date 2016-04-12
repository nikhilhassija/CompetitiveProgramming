#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;

		string S;
		cin>>S;

		int r=0;
		for(int i=0;i<S.size();i++)
			if(S[i]-'R')
				r++;

		int g=0;
		for(int i=0;i<S.size();i++)
			if(S[i]-'G')
				g++;

		int b=0;
		for(int i=0;i<S.size();i++)
			if(S[i]-'B')
				b++;

		cout<<min(r,min(g,b))<<endl;
	}
}