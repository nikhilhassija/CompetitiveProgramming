#include <bits/stdc++.h>

#define pii pair <int,int> 

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int n,q;
	cin >> n >> q;

	int A[n];
	int M[n];
	int C[n];
	int x,y;

	for(int i=0;i<n;i++)
	{
		cin >> x >> y;

		x--; y--;

		M[i] = x;
		C[x] = i;

		A[x] = y;		
	}

	pii L[n];
	vector < vector <int> > V;
	int B[n];
	memset(B,0,sizeof(B));
	int k = -1;

	for(int i=0;i<n;i++)
	{
		int x = i;

		if(B[x] == 0)
		{
			V.push_back(vector <int> ());
			k++;

			while(!B[x])
			{
				B[x] = 1;

				V[k].push_back(x);
				L[x] = {k,V[k].size()-1};

				x = A[x];
			}
		}
	}

	while(q--)
	{
		int b,t;
		cin >> b >> t;

		b--;

		int card = M[b];
		int vect = L[card].first;
		int pos  = L[card].second;

		int sz    = V[vect].size();
		int final = V[vect][(pos+t)%sz];

		cout << C[final] + 1 << endl;
	}
}