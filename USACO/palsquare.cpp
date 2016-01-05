/*
ID: nikhil14
PROG: palsquare
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

char A[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P'}; 

string num2base(int n, int b)
{
	string S = "";
	while(n)
	{
		S = S + A[n%b];
		n /= b;
	}
	return S;
}

int ispalin(string S)
{
	int l = 0;
	int r = S.size()-1;
	while(l<r)
		if(S[l++]!=S[r--])
			return 0;
	return 1;
}

int main()
{
	bool oj = true;
	if(oj)
	{
		freopen("palsquare.in","r",stdin);
		freopen("palsquare.out","w",stdout);
	}
	int b;
	cin>>b;
	for(int i=1;i<300;i++)
	{
		if(ispalin(num2base(i*i,b)))
		{
			string S = num2base(i,b);
			reverse(S.begin(),S.end());
			cout<<S<<" "<<num2base(i*i,b)<<endl;
		}
	}
}