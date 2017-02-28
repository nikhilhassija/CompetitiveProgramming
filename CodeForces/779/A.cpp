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

	int T[6];
	int A[6];

	mset(A);
	mset(T);

	for(int i=0; i<n; i++)
	{
		int x;
		cin >> x;
		A[x]++;
		T[x]++;
	}

	int B[6];
	for(int i=0; i<n; i++)
	{
		int x;
		cin >> x;
		B[x]++;
		T[x]++;
	}

	int f = 0;
	for(int i=0; i<6; i++)
		f += T[i] % 2;

	if(f)
		cout << -1 << endl;
	else
	{
		int ans = 0;
		for(int i=0; i<6; i++)
			ans += max(0, T[i]/2 - A[i]);

		cout << ans << endl;
	}

	return (0-0);	
}