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
	string S;
	cin >> S;

	int A[S.size() + 1], B[S.size() + 1];

	mset(A);
	mset(B);

	int n = S.size();

	A[0] = B[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		A[i] = A[i - 1] + (S[i - 1] == 'a');
		B[i] = B[i - 1] + (S[i - 1] == 'b');
	}

	int ans = 0;

	for (int i = 0; i <= n; i++)
		for (int j = i; j <= n; j++)
			ans = max(ans, A[i] + B[j] - B[i] + A[n] - A[j]);

	cout << ans << endl;

	return (0-0);	
}