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

int check(lli, lli, lli);

int main()
{
	int n;
	cin >> n;

	vector <int> A(n);
	for(int i=0; i<n; i++)
		cin >> A[i];

	sort(A.begin(), A.end());

	for(int i=0; i<n-2; i++)
		if(check(A[i], A[i+1], A[i+2]))
		{
			printf("YES\n");
			return 0;
		}
	printf("NO\n");
}

int check(lli a, lli b, lli c)
{
	if(a + b > c && b + c > a && c + a > b)
		return 1;
	return 0;
}