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
	int R;
	cin >> R;

	while(R--)
	{
		int L;
		cin >> L;

		string S;
		cin >> S;

		int c = 0, m = 0, M = 0;
		for(int i=0; i<L; i++)
		{
			c += (S[i] == 'H') - (S[i] == 'T');
			m = min(c, m);
			M = max(c, M);
		}

		if(m < 0 || M > 1 || c)
			cout << "Invalid" << endl;
		else
			cout << "Valid" << endl;
	}
	
	return (0-0);	
}