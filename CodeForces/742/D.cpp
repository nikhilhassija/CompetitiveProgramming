#include <bits/stdc++.h>

using namespace std;

struct node
{
	int val;
	int D[1005];
};

int P[1005];
int W[1005];
int B[1005];

int find(int);
int merge(int, int);

int main()
{
	int n,m,max_w;
	cin >> n >> m >> max_w;

	int w[n];
	for(int i=0;i<n;i++)
		cin >> w[i];

	int b[n];
	for(int i=0;i<n;i++)
		cin >> b[i];

	// DSU Init
	for(int i=0;i<n;i++)
	{
		P[i] = i;
		W[i] = w[i];
		B[i] = b[i];
	}

	while(m--)
	{
		int x, y;
		cin >> x >> y;

		x--;
		y--;

		merge(x,y);
	}

	node ans[max_w+10];
	memset(ans, 0, sizeof(ans));

	for(int i=0;i<n;i++)
	{
		int d = find(i);
		int dw = W[d];
		int db = B[d];

		for(int j=0;j<=max_w;j++)
		{
			if(ans[j].D[d] == 0)
			{
				if(j + w[i] <= max_w)
				{
					if((ans[j].val + b[i]) >= ans[j+w[i]].val) 
					{
						ans[j+w[i]].val = ans[j].val + b[i];

						for(int k=0;k<1005;k++)
							ans[j+w[i]].D[k] = ans[j].D[k];

						ans[j+w[i]].D[d] = 1; 
					}
				}

				if(j + dw <= max_w)
				{
					if((ans[j].val + db) >= ans[j+dw].val) 
					{
						ans[j+dw].val = ans[j].val + db;

						for(int k=0;k<1005;k++)
							ans[j+dw].D[k] = ans[j].D[k]; 

						ans[j+d].D[d] = 1;
					}
				}
			}
		}
	}

	int ANS = 0;
	for(int i=0;i<=max_w;i++)
		ANS = max(ANS, ans[i].val);

	cout << ANS << endl;
}

int find(int x)
{
	if(x == P[x])
		return x;

	P[x] = find(P[x]);
	return P[x];
}

int merge(int a, int b)
{
	a = find(a);
	b = find(b);

	if(a != b)
	{
		P[a] = b;
		W[b] += W[a];
		B[b] += B[a];
	}
}