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

void func(lli *, lli);

int main()
{
	lli n = 2;
	lli A[] = {0, 0};

	for(int i = 0; i <= 10; i++)
	{
		for(int j = 0; j <= 10; j++)
		{
			A[0] = i;
			A[1] = j;
			cout << i << " " << j << " = ";
			func(A, n);
		}
	}	

	return (0-0);	
}

void func(lli * A, lli n)
{
	sort(A, A + n);
	reverse(A, A + n);

	lli ans = 0;

	while(A[0] >= n)
	{
		A[0] -= n;
		for(int i = 1; i < n; i++)
			A[i]++;

		sort(A, A + n);
		reverse(A, A + n);

		ans++;
	}

	cout << ans << endl;
}