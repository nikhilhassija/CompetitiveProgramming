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
	int n;
	cin >> n;

	int A[n];

	for (int i = 0; i < n; i++)
		cin >> A[i];

	pii B[n];
	for (int i = 0; i < n; i++)
		cin >> B[i].first;

	for (int i = 0; i < n; i++)
		B[i].second = i;

	sort(B, B + n);

	sort(A, A + n);
	reverse(A, A + n);

	pii C[n];
	for (int i = 0; i < n; i++)
	{
		C[i].first = B[i].second;
		C[i].second = A[i];
	}

	sort(C, C + n);

	for (int i = 0; i < n; i++)
		cout << C[i].second << " ";
	cout << endl;

	return (0-0);	
}