#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int n,k;
	cin >> n >> k;

	unordered_map <int,int> M;

	while(n--)
	{
		int x;
		cin >> x;

		if(M.find(x) == M.end())
			M[x] = 0;

		M[x]++;
	}

	auto it = M.begin();
	for(;it!=M.end();it++)
		if(it->second != k)
		{
			cout << it->first << '\n';
			break;
		}
}