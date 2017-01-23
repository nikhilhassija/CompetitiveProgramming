#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int A[n];
	for(int &i: A)
		cin >> i;

	int DP[n];
	memset(DP, 0, sizeof(DP));

	DP[0] = 0;

	for(int i=0;i<n;i++)
	{
		int ans = 0;
		for(int j=0;j<i;j++)
			if(A[i] > A[j])
				ans = max(ans, DP[j]);

		DP[i] = ans + 1;
	}

	int ans = 0;
	for(int i: DP)
		ans = max(ans, i);

	cout << ans << endl;
}