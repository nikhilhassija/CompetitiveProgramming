/*
ID: nikhil14
PROG: barn1
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	bool oj = true;
	if(oj)
	{
		freopen("barn1.in","r",stdin);
		freopen("barn1.out","w",stdout);
	}
	int m,s,c,x,i;
	cin>>m>>s>>c;
	vector <int> A(s,0);
	for(i=0;i<c;i++)
	{
		cin>>x;
		A[x-1] = 1;
	}
	vector <int> C;
	int count = 0;
	for(i=0;i<s;i++)
	{
		if(!A[i])
			count++;
		else if(count)
		{
			C.push_back(count);
			count = 0;
		}
	}
	C.push_back(count);
	if(!A[0])
	{
		s -= C[0];
		C[0] = 0;
	}
	if(!A[A.size()-1])
	{
		s -= C[C.size()-1];
		C[C.size()-1] = 0;
	}
	sort(C.rbegin(),C.rend());
	m--;
	i = 0;
	while(m--)
	{
		s -= C[i++];
		if(i>=C.size())
			break;
	}
	cout<<s<<endl;
}