/*
ID: nikhil14
PROG: crypt1
LANG: C++11
*/
#include <bits/stdc++.h>

bool oj = false;
using namespace std;

vector <bool> X(10,false);
vector <int> A;

int check(int n)
{
	bool res = true;
	while(n)
	{
		res = res && X[n%10];
		n /= 10;
	}
	return res;
}

int makenum(int a, int b, int c)
{
	return a*100 + b*10 + c;
}

int isprime(int x)
{
	switch(x)
	{
		case 2: 
		case 3: 
		case 5: 
		case 7: return true;
		default: return false;
	}
}

int main()
{
	if(oj)
	{
		freopen("crypt1.in","r",stdin);
		freopen("crypt1.out","w",stdout);
	}
	int n;
	int count = 0;
	cin>>n;
	A.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
		X[A[i]] = true;
	}
	for(int a=0;a<n;a++)
	{
		for(int b=0;b<n;b++)
		{
			for(int c=0;c<n;c++)
			{
				for(int d=0;d<n;d++)
				{
					for(int e=0;e<n;e++)
					{
						int x = makenum(A[a],A[b],A[c]);
						int y = makenum(0,A[d],A[e]);
						if(99<x*A[d]<1000 && 99<x*A[e]<1000 && 999<x*y<10000 && check(x*A[d]) && check(x*A[e]) && check(x*y) && isprime(A[a]) && isprime(A[b]) && isprime(A[c]) && isprime(A[d]) && isprime(A[e]))
							count++;
					}
				}
			}
		}
	}
	cout<<count<<endl;
}