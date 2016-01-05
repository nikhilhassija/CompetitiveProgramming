/*
ID: nikhil14
PROG: dualpal
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

char A[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P'}; 
int check(int);
int ispalin(string);
string num2base(int,int);

int main()
{
	bool oj = true;
	if(oj)
	{
		freopen("dualpal.in","r",stdin);
		freopen("dualpal.out","w",stdout);
	}
	int n,s;
	cin>>n>>s;
	for(int i=s+1;n;i++)
	{
		if(check(i))
		{
			cout<<i<<endl;
			n--;
		}
	}
}

int check(int n)
{
	int c = 0;
	for(int i=2;i<=10;i++)
		if(ispalin(num2base(n,i)))
			c++;
	return c>1;
}

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