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
	
	sort(A, A+n);
	for(int i=1; i+1<n; i+=2)
		swap(A[i], A[i+1]);

	for(int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;

	return (0-0);	
}