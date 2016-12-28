#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))

using namespace std;

int main()
{
	string A, B;
	cin >> A >> B;

	map < char, set<char> > M;

	for(int i=0;i<A.size();i++)
		M[A[i]].insert(B[i]);

	map <char, char> S;
	for(auto i=M.begin(); i!=M.end(); i++)
	{
		if(i->second.size() > 1)
		{
			printf("-1\n");
			return 0;
		}
		else if(i->second.size())
		{
			auto p = i->second.begin();
			S[i->first] = *p;
		}
	}

	set < pair <char, char> > s;
	for(auto i=S.begin(); i!=S.end(); i++)
	{
		auto u = i->first;
		auto v = i->second;
		if(S.find(v) != S.end() && S[v] != u)
		{
			printf("-1\n");
			return 0;
		}
		else
		{
			auto m = min(u,v);
			auto M = max(u,v);
			if(m != M)
			{
				S[m] = M;
				S[M] = m;
				s.insert({m,M});
			}
		}
	}

	cout << s.size() << endl;

	for(auto i=s.begin(); i != s.end(); i++)
		printf("%c %c\n", (*i).first, (*i).second);
}