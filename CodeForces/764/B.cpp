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

	int A[n];
	for(int i=0; i<n; i++)
		cin >> A[i];

	for(int i=0; i<n/2; i++)
		if(i % 2 == 0)
			swap(A[i], A[n-1-i]);

	for(int i=0; i<n; i++)
		printf("%d ", A[i]);
	cout << endl;	
}