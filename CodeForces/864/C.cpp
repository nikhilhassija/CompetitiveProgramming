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
	int a, b, f, k;
	cin >> a >> b >> f >> k;

	int dir = 1;
	int cur = b - f;

	int ref = 0;

	if (cur < 0 or b < (2 * (a - f)) or b < (2 * f))
	{
		cout << -1 << endl;
		return 0;
	}

	while (k)
	{
		if (dir)
		{
			if (k == 1)
			{
				if (cur < (a - f))
					ref++;

				break;
			}

			if (2 * (a - f) > cur)
			{
				// cout << "going A: " << cur << " - " << (2 * (a - f)) << endl;		
				cur = b;
				ref++;
			}

			cur -= 2 * (a - f);

			dir = 0;

			k--;
		}
		else
		{
			if (k == 1)
			{
				if (cur < f)
					ref++;

				break;
			}


			if (2 * f > cur)
			{
				// cout << "going B: " << cur << " - " << (2 * f) << endl;
				cur = b;
				ref++;
			}

			k--;

			cur -= 2 * f;

			dir = 1;
		}
	}

	cout << ref << endl;
	
	return (0-0);	
}