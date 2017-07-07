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
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		int A[1002];
		mset(A);
		A[0] = 1;
		int k = 0;

		vector <int> S;

		while(S.size() < n and k <= 500)
		{
			while(k <= 500 and A[k]) 
				k++;

			for(int i=0; i<S.size(); i++)
				A[S[i] + k] = 1;

			A[k] = 1;
			S.pb(k);
		}

		for(int i=0; i<n; i++)
			cout << S[i] << " ";
		cout << endl;
	}

	return (0-0);	
}