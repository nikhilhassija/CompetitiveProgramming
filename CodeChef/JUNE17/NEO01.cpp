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
	int t;
	cin >> t;

	while(t--)
	{
		lli n;
		cin >> n;

		vector <lli> A(n);
		for(int i=0; i<n; i++)
			cin >> A[i];

		sort(A.rbegin(), A.rend());

		lli ans = 0;
		lli sum = 0;
		lli cnt = 0;

		for(int i=0; i<n; i++)
		{
			if(sum*cnt < ((sum + A[i]) * (cnt + 1)))
			{
				sum += A[i];
				cnt += 1;
			}
			else
			{
				ans += sum * cnt;
				sum = A[i];
				cnt = 1;
			}
		}

		ans += sum * cnt;

		cout << ans << endl;
	}

	return (0-0);	
}