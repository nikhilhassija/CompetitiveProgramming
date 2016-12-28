#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, c;
	cin >> n >> c;

	int A[n];
	for(int i=0;i<n;i++)
		cin >> A[i];

	int ans = 0;
	for(int i=0;i<n-1;i++)
		ans = max(ans, A[i] - A[i+1] - c);

	cout << ans << endl;
}