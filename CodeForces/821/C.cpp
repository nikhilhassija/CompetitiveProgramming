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
	int n;
	cin >> n;

	int next = 1;
	int ans = 0;
	int tot = 0;

	stack < pii > S;

	for(int i=0; i<2*n; i++)
	{
		string q;
		cin >> q;

		if(q == "add")
		{
			tot++;

			int x;
			cin >> x;

			if(S.empty())
			{
				S.push({x, 1});		
			}
			else
			{
				auto t = S.top();
				S.pop();

				if(x == (t.first - 1))
				{
					t.first = x;
					t.second++;

					S.push(t);
				}				
				else
				{
					S.push(t);
					S.push({x, 1});
				}
			}
		}
		else
		{
			auto t = S.top();
			S.pop();

			if(t.first == next)
			{
				t.first = next + 1;
				t.second--;

				if(t.second)
					S.push(t);
			}
			else
			{
				ans ++;
				t.second = tot - 1;
				t.first = next + 1; 
				S = stack <pii>();
				S.push(t);
			}

			tot--;
			next++;
		}
	}

	cout << ans << endl;

	return (0-0);	
}