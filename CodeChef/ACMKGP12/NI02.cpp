#include <bits/stdc++.h>

#define pii pair<int,int>

using namespace std;

struct point
{
	int x;
	int y;
};

point A[2600];
int D[2600][2600];

int dist(point, point);
int djikstra(int);

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		for(int i=1;i<=n;i++)
			cin >> A[i].x >> A[i].y;

		cin >> A[0].x >> A[0].y;
		cin >> A[n+1].x >> A[n+1].y;

		for(int i=0;i<n+2;i++)
			for(int j=0;j<n+2;j++)
				D[i][j] = dist(A[i],A[j]);

		printf("%d\n", djikstra(n+2));
	}
}

int dist(point a, point b)
{
	int dx = (a.x - b.x);
	int dy = (a.y - b.y);
	return dx*dx + dy*dy; 
}

int djikstra(int n)
{
	priority_queue <pii, vector<pii>,greater<pii>> Q;

	int C[n];
	for(int i=0;i<n;i++)
		C[i] = INT_MAX;

	C[0] = 0;

	Q.push({0,0});

	int V[n];
	memset(V,0,sizeof(V));

	while(!Q.empty())
	{
		auto p = Q.top();
		Q.pop();

		if(p.second == n-1)
			return p.first;

		if(V[p.second])
			continue;
		else
			V[p.second] = 1;

		for(int i=0;i<n;i++)
		{
			C[i] = min(C[i],C[p.second]+D[p.second][i]);
			if(!V[i])
				Q.push({C[i],i});
		}
	}

	return C[n-1];
}