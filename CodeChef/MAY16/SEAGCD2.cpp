#include <bits/stdc++.h>

using namespace std;

vector < vector <int> > C(102);
int M[102][102];

void coprime(int);

int main()
{
	for(int i=2;i<101;i++)
		coprime(i);

	memset(M,0,sizeof(M));

	int D[101];

	for(int i=100;i>1;i--)
	{
		for(int j=0;j<C[i].size();j++)
			D[C[i][j]] = 1;
		work(D,i,l,1);
		memset(D,0,sizeof(D));
	}
}

void coprime(int x)
{
	for(int i=x-1;i>1;i--)
		if(__gcd(x,i) == 1)
			C[x].push_back(i);
}

void work(int * D, int m, int l, int s)
{
	for(int i=0;i<100;i)
}