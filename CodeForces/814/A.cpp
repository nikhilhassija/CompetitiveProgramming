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
	int n, k;
	cin >> n >> k;

	int A[n], B[k];
	for(int i=0; i<n; i++)
		cin >> A[i];

	for(int i=0; i<k; i++)
		cin >> B[i];

	sort(B, B+k);
	reverse(B, B+k);

	int j = 0;
	for(int i=0; i<n; i++)
		if(not A[i])
			A[i] = B[j++];

	int f = 1;

	for(int i=1; i<n; i++)
		f = f and (A[i] > A[i-1]);

	if(f)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;

	return (0-0);	
}