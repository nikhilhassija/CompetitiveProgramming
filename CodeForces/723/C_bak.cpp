#include <bits/stdc++.h>

#define pii pair <int,int>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;;

	int A[n];
	for(int i=0;i<n;i++)
		cin >> A[i];

	for(int i=0;i<n;i++)
		A[i]--;

	int B[m];
	memset(B,0,sizeof(B));

	for(int i=0;i<n;i++)
		if(A[i] < m)
			B[A[i]]++;

	priority_queue <pii, vector<pii>, greater<pii> > Q;

	int sum = 0;
	for(int i=0;i<m;i++)
	{
		sum += B[i];

		Q.push({B[i],i});
	}

	while(1)
	{
		auto p = Q.top();
		Q.pop();

		vector <pii> V = {p};

		while(Q.top().first == p.first && !Q.empty())
		{
			V.push_back(Q.top());
			Q.pop();
		} 

		int d = Q.top().first - p.first;

		int a = (n - sum)/V.size();

		if(a >= 0)
		{
			for(int i=0;i<V.size();i++)
				Q.push({V[i].first + a, V[i].second});

			sum += a*V.size();

			if(!a)
				break;
		}
		else 
			break;
	}

	int ans = Q.top().first;
	int change = 0;

	int k = 0;
	while(!Q.empty())
	{
		auto p = Q.top();
		Q.pop();

		int dif = p.first - B[p.second];

		change += dif;

		while(dif)
		{
			if(A[k] >= m)
			{
				dif--;
				A[k] = p.second;
			}

			k++;
		}
	}

	printf("%d %d\n",ans,change);

	for(int i=0;i<n;i++)
		printf("%d ",A[i] + 1);
	printf("\n");
}