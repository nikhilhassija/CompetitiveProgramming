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

	if(n < 3)
	{
		cout << 1 << endl; 
		for(int i=0; i<n; i++)
			cout << 1 << " ";
		cout << endl;

		return 0;
	}

	int A[n+2];
	mset(A);

	for(int i=2; i<=n+1; i++)
	{
		if(!A[i])
		{
			for(int j=2*i; j<=n+1; j+=i)
				A[j] = 1;
		}
	}	

	cout << 2 << endl;
	for(int i=2; i<=n+1; i++)
		cout << A[i] + 1 << " ";
	cout << endl;
}