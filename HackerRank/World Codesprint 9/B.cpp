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

const int n = 1e7 + 5;
int U[n];

int main()
{
	string S;
	cin >> S;

	memset(U, 0, sizeof(U));

	int c = 1;
	int w = (S[0] - 'a') + 1;

	U[c*w] = 1;

	for(int i=1; i<S.size(); i++)
	{

		if(S[i] != S[i-1])
		{
			c = 1;
			w = (S[i] - 'a') + 1;	
		}	
		else
		{
			c++;
		}
		
		U[c*w] = 1;
	}

	int q;
	cin >> q;

	while(q--)
	{
		int x;
		cin >> x;

		if(U[x])
			printf("Yes\n");
		else
			printf("No\n");
	}
}