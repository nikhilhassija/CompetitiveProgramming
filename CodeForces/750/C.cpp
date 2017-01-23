#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))
#define fastio() ios_base::sync_with_stdio(0);

using namespace std;

const int inf = 1e9;

int main()
{
	int t;
	cin >> t;

	priority_queue <int, vector <int>, greater<int> > L;
	priority_queue <int> G;

	int del = 0;

	int d,c;

	while(t--)
	{
		cin >> c >> d;

		if(d == 1)
		{
			G.push(1900 + del);
		} 

		if(d == 2)
		{
			L.push(1899 + del);
		}

		del -= c;
	}

	if(L.empty())
	{
		printf("Infinity\n");
	}
	else
	{
		int a, b;

		if(!G.empty())
			a = G.top();
		else
			a = -inf;

		b = L.top();

		if(a <= b)
		{
			int x = b - del;
			cout << x << endl;
		}
		else
			printf("Impossible\n");
	}
}