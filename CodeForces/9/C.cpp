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

vector <int> A;

int decbin(int);
void init();

int main()
{
	int n;
	cin >> n;

	init();

	int ans = 0;
	for(int i = 0; i < A.size(); i++)
		if(A[i] <= n)
			ans ++;

	cout << ans << endl;
	
	return (0-0);	
}

int decbin(int a)
{
	vector <int> X;

	while(a)
	{
		X.pb(a % 2);

		a /= 2;
	}

	int ret = 0;
	reverse(X.begin(), X.end());

	for(int i = 0; i < X.size(); i++)
		ret = ret * 10 + X[i];

	return ret;
}


void init()
{
	for(int i = 1; i < 1025; i++)
		A.pb(decbin(i));

	sort(A.begin(), A.end());
}