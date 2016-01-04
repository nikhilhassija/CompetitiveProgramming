/*
ID: nikhil14
PROG: gift1
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

bool oj = true;

int main()
{
	if(oj)
	{
		freopen("gift1.in","r",stdin);
		freopen("gift1.out","w",stdout);
	}
	int n,x,c,i;
	string P;
	cin>>n;
	vector <string> A(n);
	map <string, int> M;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
		M[A[i]] = 0;
	}
	for(i=0;i<n;i++)
	{
		cin>>P;
		cin>>x>>c;
		M[P] -= x;
		if(c)
		{
			M[P] += x%c;
			x /= c;
		}
		while(c--)
		{
			cin>>P;
			M[P] += x;
		}
	}
	for(i=0;i<n;i++)
		cout<<A[i]<<" "<<M[A[i]]<<endl;
}