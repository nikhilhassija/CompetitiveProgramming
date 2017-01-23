#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;

	for(int x = 0; x < t; x++)
	{
		printf("Case #%d: ", x+1);

		int n;
		cin >> n;

		int A[n];
		for(int &i: A)
			cin >> i;

		sort(A, A + n);
		reverse(A, A + n);

		int l = 0;
		int r = n - 1;
		int sum = A[l];
		int ans = 0;

		while(l < r)
		{
			if(sum >= 50)
			{
				ans++;

				l++;
				sum = A[l];
			}
			else
			{
				sum += A[l];
				r--;
			}
		}

		if(sum >= 50)
			ans ++;

		cout << ans << endl;
	}
}