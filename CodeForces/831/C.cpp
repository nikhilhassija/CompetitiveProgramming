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

const int MAX_N = 1e7;
const int off   = 5e6;
vector <int> C(MAX_N, 0);

int main()
{
	int k, n;
	cin >> k >> n;
	
	int A[k], B[n];
	for(int i = 0; i < k; i++)
		cin >> A[i];

	for(int i = 0; i < n; i++)
		cin >> B[i];

	for(int i = 0; i < n; i++)
		C[B[i] + off] = -1; 

	set <int> S;
	for(int i = 0; i < k; i++)
	{
		B[0] -= A[i];
		S.insert(B[0]);
	}

	int x = 0;
	int ans = 0;

	for(int s: S)
	{
		x++;

		int cnt = 0;
		for(int i = 0; i < k; i++)
		{
			s += A[i];

			if(C[s + off] and C[s + off] < x)
			{
				C[s + off] = x;
				cnt++;
			}
		}

		if(cnt == n)
			ans++;
	}

	cout << ans << endl;

	return (0-0);	
}