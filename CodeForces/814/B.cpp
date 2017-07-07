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

int check(int *, int *, int *, int, int, int, int, int);

int main()
{
	int n;
	cin >> n;

	int A[n], B[n], C[n+1], X[n];

	mset(C);

	for(int i=0; i<n; i++)
		cin >> A[i];

	for(int i=0; i<n; i++)
		cin >> B[i];

	int m = 0;

	for(int i=0; i<n; i++)
	{
		if(A[i] == B[i])
			X[i] = A[i];
		else
		{
			X[i] = 0;
			m++;
		}
	}

	if(m == 1)
	{
		int x = 0;
		for(int i=0; i<n; i++)
			if(not X[i])
				x = i;

		for(int i=1; i<=n; i++)
		{
			if(check(A, B, X, i, -1, x, -1, n))
			{
				for(int j=0; j<n; j++)
				{
					if(j != x)
						cout << X[j] << " ";
					else
						cout << i << " "; 
				}

				return 0;
			}
		}
	}

	if(m == 2)
	{
		int x = -1, y = -1;
		for(int i=0; i<n; i++)
		{
			if(not X[i] and x == -1)
			{
				x = i;
			}
			else if(not X[i])
			{
				y = i;
			}
		}

		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(i != j)
				{
					if(check(A, B, X, i+1, j+1, x, y, n))
					{
						for(int k=0; k<n; k++)
						{	
							if(k == x)
								cout << i+1 << " ";
							else if(k == y)
								cout << j+1 << " ";
							else
								cout << X[k] << " ";
						}

						cout << endl;
						return 0;
					}
				}
			}
		}
	}

	return (0-0);	
}

int check(int * A, int * B, int * X, int x, int y, int l, int r, int n)
{
	int ma = 0;
	int mb = 0;
	int sum = 0;

	for(int i=0; i<n; i++)
	{
		if(i == l)
		{
			X[i] = x;
		}

		if(i == r)
		{
			X[i] = y;
		}

		sum += X[i];

		if(X[i] != A[i])
			ma++;

		if(X[i] != B[i])
			mb++;

		if(i == l or i == r)
			X[i] = 0;
	}

	int tsum = (n * (n+1)) / 2;

	return (ma == 1) and (mb == 1) and (sum == tsum);
}