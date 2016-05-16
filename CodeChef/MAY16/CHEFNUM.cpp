#include <bits/stdc++.h>

using namespace std;

long long int amaz(int);
void update(int *, int);

const int mod = 1e9 + 7;

int md(int x)
{
	while(x<0)
		x += mod;

	return x % mod;
}
const int n = 1e6 + 1;
int A[n];
vector < vector <int> > M;

int main()
{
	M.resize(121);

	for(int i=1;i<n;i++)
	{
		A[i] = amaz(i);
		M[A[i]].push_back(i);
	}

	for(int i=0;i<M.size();i++)
	{
		printf("Amaz = %d\n",i);
		int D[10];
		memset(D,0,sizeof(D));
		for(int j=0;j<M[i].size();j++)
			printf("%d ",M[i][j]);
		cout<<endl;
	}


	for(int i=1;i<n;i++)
	{
		A[i] += A[i-1];
		A[i] %= mod;
		// cout<<A[i]<<endl;
	}

	int t;
	cin>>t;

	while(t--)
	{
		int l,r;
		cin>>l>>r;

		cout<<md(A[r]-A[l-1])<<endl;
	}
}

long long int amaz(int x)
{
	vector <int> A;

	while(x)
	{
		A.push_back(x%10);
		x /= 10;
	}

	reverse(A.begin(),A.end());


	int X[16];
	memset(X,0,sizeof(X));
	long long int ans = 0;

	int n = A.size();
	for(int i=0;i<n;i++)
	{
		x = 0;
		for(int j=i;j<n;j++)
		{
			x ^= A[j];

			if(X[x] == 0)
			{
				ans += x;
				X[x] = 1;
			} 
		}
	}

	/*
	for(int i=1;i<16;i++)
		cout<<X[i];
	cout<<endl;
	*/
	return ans;
}

void update(int * A, int x)
{
	while(x)
	{
		A[x%10] = 1;
		x /= 10;
	}
}