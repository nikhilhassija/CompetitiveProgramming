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
	int n, m;
	cin >> n >> m;

	set <string> A, B;

	while(n--)
	{
		string S;
		cin >> S;

		A.insert(S);
	}	
		
	while(m--)
	{
		string S;
		cin >> S;

		B.insert(S);
	}

	int z = 0;

	set <string> X, Y;

	for(auto it = A.begin(); it != A.end(); it++)
	{
		string S = *it;
		auto _it = B.find(S);

		if(_it != B.end())
		{
			z ^= 1;
		}
		else
		{
			X.insert(S);
		}
	}

	for(auto it=B.begin(); it != B.end(); it++)
	{
		string S = *it;

		if(A.find(S) == A.end())
			Y.insert(S);
	}

	int x = X.size();
	int y = Y.size();

	if((x + z) > y)
		printf("YES\n");
	else
		printf("NO\n");
}
