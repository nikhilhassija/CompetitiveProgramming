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
	char a, b;
	cin >> a >> b;

	char A[] = {118, 60, 94, 62};

	int n;
	cin >> n;

	n %= 4;
	
	if(n % 2 == 0)
	{
		cout << "undefined" << endl;
		return 0;
	}

	int x = 0;
	for(int i = 0; i < 4; i++)
		if(A[i] == a)
			x = i;

	int y = 0;
	for(int i = 0; i < 4; i++)
		if(A[i] == b)
			y = i;

	if((x + n) % 4 == y)
		cout << "cw" << endl;
	else
		cout << "ccw" << endl;

	return (0-0);	
}