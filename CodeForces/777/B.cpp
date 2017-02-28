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

int main()
{
	int n;
	cin >> n;

	string a, b;
	cin >> a;
	cin >> b;

	int A1[10], B1[10];
	int A2[10], B2[10];
	mset(A1);
	mset(A2);
	mset(B1);
	mset(B2);

	for(int i=0; i<n; i++)
	{
		A1[a[i] - '0']++;
		A2[a[i] - '0']++;
		B1[b[i] - '0']++;
		B2[b[i] - '0']++;
	}

	for(int i=0; i<10; i++)
	{
		int x = min(A1[i], B1[i]);
		A1[i] -= x;
		B1[i] -= x;
	}

	int mn = 0;
	for(int i=9; i>=0; i--)
	{
		int x = min(A1[i], B1[i]);

		mn += A1[i] - x;

		B1[i] -= x;

		if(i)
			B1[i-1] += B1[i];
	}

	cout << mn << endl;

	int mx = 0;
	for(int i=8; i>=0; i--)
	{
		int x = min(A2[i], B2[i+1]);

		mx += x;

		B2[i] += B2[i+1] - x;
	}

	cout << mx << endl;
}