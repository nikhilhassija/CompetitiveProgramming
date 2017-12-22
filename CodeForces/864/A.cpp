#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))
#define fastio() ios_base::sync_with_stdio(0); cin.tie(NULL)

using namespace std;

int main()
{
	int n;
	cin >> n;

	int A[105];
	mset(A);

	set <int> S;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		A[x]++;

		S.insert(x);
	}
	
	if (S.size() == 2)
	{
		if (n % 2 == 0)
		{
			int x = *S.begin();

			if (A[x] == n / 2)
			{
				cout << "YES" << endl;
				cout << (*S.begin()) << " " << (*(next(S.begin()))) << endl;
				return 0;
			}
		}
	}

	cout << "NO" << endl;

	return (0-0);	
}