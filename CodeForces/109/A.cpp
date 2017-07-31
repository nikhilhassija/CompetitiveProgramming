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

	int x = n / 7;
	int s = n % 7;

	while(x >= 0 and s % 4)
	{
		x--;
		s += 7;
	}

	if(x >= 0 and s % 4 == 0)
	{
		int y = s / 4;

		while(y--)	cout << 4;
		while(x--)	cout << 7;
		cout << endl;
	}
	else
		cout << -1 << endl;
	
	return (0-0);	
}