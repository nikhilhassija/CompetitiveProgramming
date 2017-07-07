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
	int c, v0, v1, a, l;
	cin >> c >> v0 >> v1 >> a >> l;

	int days = 0;
	int speed = v0;
	int prog = 0;

	while(prog < c)
	{
		days ++;
		prog += speed;

		if(prog >= c)
		{
			break;
		}

		prog = max(0, prog - l);

		speed = min(speed + a, v1);
	}

	cout << days << endl;

	return (0-0);	
}