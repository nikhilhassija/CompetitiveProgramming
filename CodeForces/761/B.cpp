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
	int n, l;
	cin >> n >> l;

	int A[2*n];
	for(int i=0; i<n; i++)
		cin >> A[i];

	for(int i=0; i<n; i++)
		A[n+i] = A[i] + l;

	for(int i=(2*n) - 1; i>0; i--)
		A[i] -= A[i-1];

	int B[2*n];
	for(int i=0; i<n; i++)
		cin >> B[i];

	B[n] = B[0] + l;

	for(int i=n; i>0; i--)
		B[i] -= B[i-1];


	for(int i=0; i<n; i++)
	{
		int f = 0;
		for(int j=1; j<=n; j++)
			if(A[i+j] != B[j])
				f = 1;

		if(!f)
		{
			printf("YES\n");
			return 0;
		}
	}

	printf("NO\n");
}