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
	int n;
	cin >> n;

	int A[n+1];
	for(int i=1; i<=n; i++)
		cin >> A[i];

	for(int i=1; i<(n+1)/2; i+=2)
		swap(A[i], A[n+1-i]);

	for(int i=1; i<=n; i++)
		printf("%d ", A[i]);
	cout << endl;	
}