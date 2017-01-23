#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))
#define fastio() ios_base::sync_with_stdio(0);

using namespace std;

int main()
{
	int n;
	cin >> n;

	int A[n];
	for(int i=0;i<n;i++)
		cin >> A[i];

	int sum = 0;
	for(int i=0;i<n;i++)
		sum += A[i];

	if(sum)
	{
		printf("YES\n");
		printf("1\n1 %d\n", n);
	}
	else
	{
		vector <pii> P;

		int s = 0;
		int a = 0;
		for(int i=0;i<n;i++)
		{
			s += A[i];
			if(s != 0)
			{
				if(i != n-1)
				{
					P.push_back({a, i});
					s = 0;
					a = i+1;
				}
			}
		}

		if(s)
		{
			P.push_back({a, n-1});
			printf("YES\n");
			cout << P.size() << endl;

			for(int i=0;i<P.size();i++)
				printf("%d %d\n", P[i]._F + 1, P[i]._S + 1);
		}
		else
		{
			if(P.size())
			{
				int N = P.size();
				auto p = P[N-1];

				p._S = n-1;

				printf("YES\n");
				cout << P.size() << endl;
				P[N-1] = p;
				for(int i=0;i<N;i++)
					printf("%d %d\n", P[i]._F + 1, P[i]._S + 1);
			}
			else
			{
				printf("NO\n");
			}
		}
	}
}