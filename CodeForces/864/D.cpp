#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))
#define fastio() ios_base::sync_with_stdio(0); cin.tie(NULL)

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector < set <int> > P(n + 1);

	int A[n];
	for (int i = 0; i < n; i++)
		cin >> A[i];

	for (int i = 0; i < n; i++)
		P[A[i]].insert(i);

	set <pii> D;

	for (int i = 1; i <= n; i++)
		if (P[i].size() > 1)
			for (int p: P[i])
				D.insert({p, i});

	int k = 0;
	int ans = 0;

	set <int> S;

	for (int i = 1; i <= n; i++)
	{
		if (P[i].size() == 0 and (S.find(i) == S.end()))
		{
			ans++;

			auto it = D.begin();

			while ( (P[it -> second].size() == 1 and (S.find(it->second)) == S.end()) or ((it -> second < i) and (S.find(it -> second) == S.end())))
			{
				S.insert(it -> second);
				P[it -> second].erase(it -> first);
				D.erase(it);

				it = D.begin();
			}

			A[it -> first] = i;
			P[it -> second].erase(it -> first);
			D.erase(it);
		}
	}

	cout << ans << endl;
	for (int a: A)
		cout << a << " ";
	cout << endl;

	return (0-0);	
}	