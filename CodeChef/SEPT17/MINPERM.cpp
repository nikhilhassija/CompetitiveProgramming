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
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		int A[n];
		for (int i = 0; i < n; i++)
			A[i] = i + 1;

		for (int i = 0; i < n - 1; i += 2)
			swap(A[i], A[i + 1]);

		if (n % 2)
			swap(A[n - 2], A[n -1]);

		for (int a: A)
			cout << a << " ";
		cout << endl;
	}

	return (0-0);	
}