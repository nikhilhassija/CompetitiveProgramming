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
	lli b;
	cin >> b;

	string S;
	cin >> S;

	lli n = S.size();
	for(int i=0; i<n; i++)
		S[i] -= '0';

	pll DP[n+1];
	DP[n] = {0, 0};

	lli l = log10(b) + 1; 

	for(int i=n-1; i>=0; i--)
	{
		for(int j=i; j<n && (j-i)<=l; j++)
		{
			//i - j;
			lli num = 0;
			for(int k=i; k<=j; j++)
			{

			}
		}
	}		
}

lli binpow(lli b, lli e)
{
	
}