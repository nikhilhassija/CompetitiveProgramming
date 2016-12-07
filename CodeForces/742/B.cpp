#include <bits/stdc++.h>

#define lli long long int

using namespace std;

int main()
{
	int n, x;
	cin >> n >> x;

	int A[n];
	for(int i=0;i<n;i++)
		cin >> A[i];

	int max_n = 1e5 + 5;
	lli C[max_n];
	memset(C, 0, sizeof(C));

	for(int i=0;i<n;i++)
		C[A[i]]++;

	lli ans = 0;

	for(int i=0;i<max_n;i++)
	{
		int j = x ^ i;
		if(j < max_n)
		{
			ans += (C[i]*C[j]);

			if(i == j)
				ans -= C[i];
		}
	}

	ans /= 2;

	cout << ans << endl;
}

