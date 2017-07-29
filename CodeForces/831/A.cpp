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

	if(n == 1)
	{
		cout << "YES" << endl;
		return 0;
	}

	int A[n];
	for(int i = 0; i < n; i++)
		cin >> A[i];

	int f = 1;
	int i = 0;
	for(; i < (n - 1); i++)
	{
		if(A[i] > A[i + 1])
		{
			break;
			return 0;
		}
		else if(A[i] == A[i+1])
		{
			i++;
			break;
		}
	}

	for(; i < (n - 1); i++)
	{
		if(A[i] > A[i+1])
		{
			i++;
			break;
		}
		if(A[i] < A[i+1])
		{
			cout << "NO" << endl;
			return 0;
		}
	}

	for(; i < (n - 1); i++)
	{
		if(A[i] > A[i+1])
			continue;
		else
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	
	cout << "YES" << endl;

	return (0-0);	
}