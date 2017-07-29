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

	string S;
	cin >> S;
	
	int A[26];
	mset(A);

	for(auto c: S)
		A[tolower(c) - 'a'] = 1;

	int sum = 0;
	for(int a: A)
		sum += a;

	if(sum == 26)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return (0-0);	
}