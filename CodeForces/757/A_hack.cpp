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

	for(int i=0;i<S.size();i++)
	{
		if(S[i] == 'B')
			S.erase(i, 1);
	}	
}