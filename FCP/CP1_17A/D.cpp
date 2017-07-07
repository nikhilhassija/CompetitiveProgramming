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

const int MAX_N = 1e6 + 5;
int A[MAX_N];

void seive();
int check(int, int, int);

int main()
{
	seive();

	int a, b, k;
	cin >> a >> b >> k;

	int l = 1;
	int h = (b - a) + 1;

	int inf = h + 1;
	int ans = h + 1;

	while(l <= h)
	{
		int m = (l + h) / 2;

		if(check(a, b, m) >= k)
		{
			ans = min(m, ans);
			h = m - 1;
		}
		else
			l = m + 1;
	}

	if(ans == inf)
		cout << -1 << endl;
	else
		cout << ans << endl;

	return (0-0);	
}

void seive()
{
	mset(A);

	for(int i=2; i<MAX_N; i++)
	{
		if(not A[i])
		{
			for(int j=2*i; j<MAX_N; j += i)
				A[j] = 1;
		}
	}

	for(int i=2; i<MAX_N; i++)
		A[i] ^= 1;
}

int check(int a, int b, int k)
{
	if(k > (b-a+1))
		return 0;

	int sum = 0;
	for(int i=0; i<k; i++)
		sum += A[i+a];

	int ans = sum;
	for(int i=a+k; i<=b; i++)
	{
		sum += (A[i] - A[i-k]);
		ans = min(ans, sum);
	}

	return ans;
}