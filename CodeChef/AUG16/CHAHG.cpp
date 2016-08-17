#include <bits/stdc++.h>

#define pii pair<int,int>

using namespace std;

pii intersect(pii, pii);
int merge(pii, pii);
int first(pii, pii);

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;

		int H[n],M[n];
		for(int i=0;i<n;i++)
			cin>>H[i]>>M[i];

		if(n == 1)
		{
			printf("1\n0 inf\n");
			continue;
		}

		pii A[2][n-1];

		for(int i=0;i<n-1;i++)
		{
			pii p;
			if(H[i] > H[i+1])
			{
				p.first = 0;

				int d = H[i+1] - H[i];
				int s = M[i+1] - M[i];

				if(s*d < 0)
				{
					d = abs(d);
					s = abs(s);

					p.second = (d-1)/s;					
				}
				else
					p.second = INT_MAX;
			}
			else
			{
				int d = H[i+1] - H[i];
				int s = M[i+1] - M[i];

				if(s*d < 0)
				{
					d = abs(d);
					s = abs(s);

					p.first = (d+s-1)/s;

					if((H[i] + p.first*M[i]) <= (H[i+1] + p.first*M[i+1]))
						p.first++;

					p.second = INT_MAX;
				}
				else if(d == 0 && s>0)
				{
					p.first = 1;
					p.second = INT_MAX;
				}
				else
				{
					p.first = -1;
					p.second = -1;
				}
			}

			A[0][i] = p;
		}

		for(int i=0;i<n-1;i++)
		{
			pii p;

			if(H[i] < H[i+1])
			{
				p.first = 0;

				int d = H[i+1] - H[i];
				int s = M[i+1] - M[i];

				if(d*s < 0)
				{
					s = abs(s);

					p.second = (d-1)/s;
				}
				else
					p.second = INT_MAX;
			}
			else
			{
				int d = H[i+1] - H[i];
				int s = M[i+1] - M[i];

				if(s*d < 0)
				{
					d = abs(d);
					s = abs(s);

					p.first = (d+s-1)/s + 1;

					if((H[i] + p.first*M[i]) >= (H[i+1] + p.first*M[i+1]))
						p.first++;

					p.second = INT_MAX;
				}
				else if(d == 0 && s<0)
				{
					p.first = 1;
					p.second = INT_MAX;
				}
				else
				{
					p.first = -1;
					p.second = -1;
				}
			}

			A[1][i] = p;

		}
		pii a = make_pair(0,INT_MAX);
		pii b = a;

		int x = 0;
		for(int i=0;i<n-1;i++)
		{
			a = intersect(a,A[x][i]);
			x ^= 1;
		}

		x = 1;
		for(int i=0;i<n-1;i++)
		{
			b = intersect(b,A[x][i]);
			x ^= 1;
		}			

		if(a.first != -1 && merge(a,b))
		{
			printf("1\n%d ",a.first);

			if(b.second == INT_MAX)
				printf("inf\n");
			else
				printf("%d\n",b.second);
		}
		else if(b.first != -1 && merge(b,a))
		{
			printf("1\n%d ",b.first);

			if(a.second == INT_MAX)
				printf("inf\n");
			else
				printf("%d\n",a.second);
		}
		else
		{
			if(first(b,a))
				swap(a,b);

			int ans = (a.first != -1) + (b.first != -1);

			printf("%d\n",ans);

			if(a.first != -1)
			{
				printf("%d ",a.first);

				if(a.second == INT_MAX)
					printf("inf\n");
				else
					printf("%d\n",a.second);
			}

			if(b.first != -1)
			{
				printf("%d ",b.first);

				if(b.second == INT_MAX)
					printf("inf\n");
				else
					printf("%d\n",b.second);
			}
		}

		/*printf("\n>\n");
		for(int i=0;i<n-1;i++)
			printf("%d -- %d %d\n",i,A[0][i].first,A[0][i].second);

		printf("\n<\n");
		for(int i=0;i<n-1;i++)
			printf("%d -- %d %d\n",i,A[1][i].first,A[1][i].second);
		printf("\n");*/
	}
}

pii intersect(pii a, pii b)
{
	if(a.first == -1 || b.first == -1)
		return make_pair(-1,-1);

	pii p;
	p.first = max(a.first,b.first);
	p.second = min(a.second,b.second);

	if(p.first > p.second)
		return make_pair(-1,-1);

	return p;
}

int merge(pii a, pii b)
{
	if(a.second + 1 == b.first)
		return 1;

	return 0;
}

int first(pii b, pii a)
{
	if(b.second < a.first)
		return 1;

	return 0;
}