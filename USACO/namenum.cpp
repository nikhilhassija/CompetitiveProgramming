/*
ID: nikhil14
PROG: namenum
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int num(char);

long long int namenum(string S)
{
	long long int n=0;
	for(int i=0;i<S.size();i++)
		n = n*10 + num(S[i]);
	return n;
}

int num(char a)
{
	switch(a)
	{
		case 'A': return 2;
		case 'B': return 2;
		case 'C': return 2;
		case 'J': return 5;
		case 'K': return 5;
		case 'L': return 5;
		case 'T': return 8;
		case 'U': return 8;
		case 'V': return 8;
		case 'D': return 3;
		case 'E': return 3;
		case 'F': return 3;
		case 'M': return 6;
		case 'N': return 6;
		case 'O': return 6;
		case 'W': return 9;
		case 'X': return 9;
		case 'Y': return 9;
		case 'G': return 4;
		case 'H': return 4;
		case 'I': return 4;
		case 'P': return 7;
		case 'R': return 7;
		case 'S': return 7;
	}
}

int main()
{
	ifstream din ("dict.txt");
	vector < pair<string,long long int> > A;
	string S;
	while(din>>S)
		A.push_back(make_pair(S,namenum(S)));

	freopen("namenum.in","r",stdin);
	freopen("namenum.out","w",stdout);
	
	long long int n;
	cin>>n;
	int count = 0;
	for(int i=0;i<A.size();i++)
	{
		if(A[i].second == n)
		{
			cout<<A[i].first<<endl;
			count = 1;
		}
	}
	if(!count)
		cout<<"NONE"<<endl;
}