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

int win(int, int);

int main()
{
	int p, x, y;
	cin >> p >> x >> y;

	int u = 0;

	while((x - u) >= y)
	{
		if(win(x - u, p))
		{
			cout << 0 << endl;
			return 0;
		}

		u += 50;
	}

	for(int i=0; i<5000; i++)
	{
		if(win(x + (50 * i), p))
		{
			int s = i/2 + (i % 2);
			cout << s << endl;

			return 0;
		}
	}

	return (0-0);	
}

int win(int s, int p)
{
	int x = (s / 50) % 475;

	for(int i=0; i<25; i++)
	{
		x = ((x * 96) + 42) % 475;

		if((26 + x) == p)
			return 1;
	} 

	return 0;
}