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

int main()
{
	int n;
	cin >> n;

	int A[n];
	for(int i=0; i<n; i++)
		cin >> A[i];

	int B[n];	
	for(int i=0; i<n; i++)
		cin >> B[i];

	set <int> S;
	for(int i=1; i<n; i++)
		S.insert(i);

	int X[n];
	for(int i=0; i<n; i++)
		X[i] = A[i] - 1;

	int x = 0;

	while(1)b
	{
		if(S.find(X[x]) == S.end())
		{
			if(S.empty())
			{
				X[x] = 0;
				break;
			}
			else
			{
				X[x] = *(S.begin());
			}
		}

		S.erase(X[x]);

		x = X[x];
	}

	for(int i=0; i<n; i++)
		X[i]++;

	int ans = 0;
	for(int i=0; i<n; i++)
	{
		ans += (A[i] != X[i]);
	}

	int b = 0;
	for(int i=0; i<n; i++)
		b += B[i];

	ans += 1 ^ (b%2);

	cout << ans << endl;
}