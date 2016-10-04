#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a,b,c;
	cin >> a >> b >> c;

	int ans = 305;
	for(int i=1;i<=100;i++)
		ans = min(ans, abs(a-i) + abs(b-i) + abs(c-i));

	cout << ans << endl;
}