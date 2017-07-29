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
	int m, s;
	cin >> m >> s;

	if(s == 0)
	{
		if(m == 1)
			cout << "0 0" << endl;
		else
			cout << "-1 -1" << endl;
	
		return 0;
	}

	if(s > 9 * m)
	{
		cout << "-1 -1" << endl;
		return 0;
	}

	int L[m];
	int R[m];

	mset(L);
	mset(R);

	L[0] = 1;

	int sum = 1;
	for(int i = m - 1; i > 0; i--)
	{
		if(sum + 9 <= s)
		{
			L[i] = 9;
			sum += 9;
		}
		else
		{
			L[i] = s - sum;
			sum = s;

			break;
		}
	}

	if(sum < s)
		L[0] += s - sum;

	if(s < 9)
		R[0] = s;
	else
		R[0] = 9;

	sum = R[0];

	for(int i = 1; i < m; i++)
	{
		if(sum + 9 <= s)
		{
			R[i] = 9;
			sum += 9;
		}
		else
		{
			R[i] = s - sum;
			sum = s;

			break;
		}
	}	

	for(int i = 0; i < m; i++)
		cout << L[i];

	cout << " ";

	for(int i = 0; i < m; i++)
		cout << R[i];

	cout << endl;

	return (0-0);	
}