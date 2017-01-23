#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 5;

vector <int> P;

void seive ();
int check (int);

int main ()
{
	ios_base::sync_with_stdio(false);

	seive ();

	int t;
	cin >> t;

	while (t--)
	{
		int l, r;
		cin >> l >> r;

		l = max(l, 2);

		for (int i=l; i<=r; i++)
			if (check(i))
				cout << i << endl;

		cout << endl;
	}
}

void seive ()
{
	int A[MAX_N];
	memset(A, 0, sizeof(A));

	for (int i=2; i<MAX_N; i++)
	{
		if (!A[i])
		{
			P.push_back(i);

			for(int j=2*i; j<MAX_N; j+=i)
				A[j] = 1;
		}
	}
}

int check(int x)
{
	for(int i=0; i<P.size() && P[i]<=sqrt(x); i++)
	{
		if(x % P[i] == 0)
			return 0;
	}

	return 1;
}