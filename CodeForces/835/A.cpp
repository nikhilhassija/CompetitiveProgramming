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
	int s, v1, v2, t1, t2;
	cin >> s >> v1 >> v2 >> t1 >> t2;

	int time1 = 2 * t1 + s * v1;
	int time2 = 2 * t2 + s * v2;
	
	if(time1 > time2)
		cout << "Second" << endl;
	else if(time2 > time1)
		cout << "First" << endl;
	else
		cout << "Friendship" << endl;

	return (0-0);	
}