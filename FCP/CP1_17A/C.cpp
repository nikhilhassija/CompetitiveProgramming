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

	int A[n+2];
	for(int i=0; i<n; i++)
		cin >> A[i];

	int inf = 1e9 + 1;

	A[n] = 0;
	A[n+1] = inf;

	stack <int> G, S;

	G.push(n+1);
	S.push(n);

	int NG[n], NS[n];

	for(int i=n-1; i>=0; i--)
	{
		while(A[i] >= A[G.top()]) G.pop();
		NG[i] = G.top();
		G.push(i);

		while(A[i] <= A[S.top()]) S.pop();
		NS[i] = S.top();
		S.push(i);
	}

	int ans = 0;
	for(int i=0; i<n; i++)
	{
		if(NG[i] == n+1)
		{
			ans += 15;
			continue;
		}
		if(NS[NG[i]] == n)
		{
			ans += 10;
			continue;
		}

		ans += 5;
	}

	cout << ans << endl;

	return (0-0);	
}