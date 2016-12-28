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
	int n, m, c;
	cin >> n >> m >> c;

	char s;
	if(c%2)
		s = 'L';
	else
		s = 'R';

	c = (c-1)/2;

	if(m == 1)
		c++;

	printf("%d %d %c\n", (c+m)/m, (c)%m + 1, s);	
}