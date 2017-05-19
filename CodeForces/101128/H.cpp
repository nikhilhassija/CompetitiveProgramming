#include <bits/stdc++.h>

#define lli unsigned long long
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))
#define fastio() ios_base::sync_with_stdio(0)

using namespace std;

set <lli> S;

void sheldon();
lli bin1(int, int, int);
lli bin2(int, int, int);

int main()
{
	sheldon();

	vector <lli> A(S.begin(), S.end());

	lli x, y;
	cin >> x >> y;

	int index = upper_bound(A.begin(), A.end(), y)
				- lower_bound(A.begin(), A.end(), x);

	cout << index << endl;

	return (0-0);	
}

void sheldon()
{
	for(int i=1; i<=64; i++)
		for(int j=1; j<64; j++)
		{
			for(int k=1; ((i + j)*k - j) <= 64; k++)
				S.insert(bin1(i, j, k));
			
			for(int k=1; ((i + j)*k) <= 64; k++)
				S.insert(bin2(i, j, k));
		}
}

lli bin1(int x, int y, int z)
{
	string S = "";

	for(int i=0; i<64; i++)
		S.pb(0);

	int k = 63;
	for(int i=0; i<x; i++)
		S[k--] = 1;

	for(int i=0; i<(z-1); i++)
	{
		for(int j=0; j<y; j++)
			S[k--] = 0;

		for(int j=0; j<x; j++)
			S[k--] = 1;
	}

	lli b = 0;
	for(int i=0; i<64; i++)
		b = (b * 2) + S[i];

	return b;
}


lli bin2(int x, int y, int z)
{
	string S = "";

	for(int i=0; i<64; i++)
		S.pb(0);

	int k = 63;

	for(int i=0; i<(z); i++)
	{
		for(int j=0; j<y; j++)
			S[k--] = 0;

		for(int j=0; j<x; j++)
			S[k--] = 1;
	}

	lli b = 0;
	for(int i=0; i<64; i++)
		b = (b * 2) + S[i];

	return b;
}