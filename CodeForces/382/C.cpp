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

	if(n == 1)
	{
		cout << -1 << endl;
		return 0;
	}

	int A[n];
	for(int i = 0; i < n; i++)
		cin >> A[i];

	sort(A, A + n);

	int d = min(A[1] - A[0], A[n - 1] - A[n - 2]);
	int f =  -1 ;
	for(int i = 1; i < n; i++)
		if((A[i] - A[i - 1]) != d)
		{
			if(A[i] - A[i - 1] == 2 * d and f == -1)
			{
				f = i - 1;
			}
			else
			{
				cout << 0 << endl;
				return 0;
			}
		}

	if(f != -1)
	{
		cout << 1 << endl;
		cout << A[f] + d << endl;
		return 0;
	}

	if(n == 2 and d and not (d % 2))
	{
		cout << 3 << endl;
		cout << A[0] - d << " ";
		cout << A[0] + d/2 << " ";
		cout << A[n - 1] + d << endl;
	}
	else if(not d)
	{
		cout << 1 << endl;
		cout << A[0] << endl;
	}
	else
	{
		cout << 2 << endl;
		cout << A[0] - d << " ";
		cout << A[n - 1] + d << endl;
	}

	return (0-0);	
}