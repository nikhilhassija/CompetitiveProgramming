#include <bits/stdc++.h>

#define lli long long int 

using namespace std;

lli maxgames(lli);

map <lli, lli> M;

int main()
{
	lli n;
	cin >> n;

	M[0] = 0;
	M[1] = 0;

	cout << maxgames(n) << endl;
}

lli maxgames(lli n)
{
	if(M.find(n) != M.end())
		return M[n];

	M[n] =  1 + max(n/2, n - (n/2));

	return M[n];
}