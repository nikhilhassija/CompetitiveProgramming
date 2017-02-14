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
	string S;
	cin >> S;

	int A[26];
	memset(A, 0, sizeof(A));

	int x = -1;
	for(int i=0; i<S.size(); i++)
	{
		if(S[i] - 'a' - x > 1)
		{
			printf("NO\n");
			return 0;
		}

		x = max(x, S[i] - 'a');
	}

	printf("YES\n");
}