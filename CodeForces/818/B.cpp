#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))
#define fastio() ios_base::sync_with_stdio(0)

using namespace std;

int n, m;

int steps(int, int);

int main()
{
	cin >> n >> m;

	int N[m];
	for(int i=0; i<m; i++)
		cin >> N[i];

	int C[n+1];
	mset(C);
	C[0] = 1;

	int A[n+1];
	mset(A);
	A[0] = -1;

	for(int i=0; i<m-1; i++)
	{
		int s = steps(N[i], N[i+1]);

		if(C[s])
		{
			if(not A[N[i]] or (A[N[i]] != s))
			{
				cout << -1 << endl;
				return 0;
			}

		}
		else
		{
			if(A[N[i]])
			{
				if(A[N[i]] != s)
				{
					cout << -1 << endl;
					return 0;
				}
			}
			else
			{
				A[N[i]] = s;
				C[s] = 1;
			}
		}
	}

	int k = 1;

	for(int i=1; i<=n; i++)
	{
		if(A[i])
			cout << A[i] << " ";
		else
		{
			while(C[k]) k++;
			cout << k++ << " ";
		}
	}

	return (0-0);	
}

int steps(int a, int b)
{
	if(a == b)
		return n;

	return (n + (b - a)) % n;
}