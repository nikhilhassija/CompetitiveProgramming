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

	int A[3];
	mset(A);

	while(n--)
	{
		int F[3];
		for(int i = 0; i < 3; i++)
			cin >> F[i];

		for(int i = 0; i < 3; i++)
			A[i] += F[i];
	}

	for(int i = 0; i < 3; i++)
		if(A[i])
		{
			cout << "NO" << endl;
			return 0;
		}

	cout << "YES" << endl;

	return (0-0);	
}