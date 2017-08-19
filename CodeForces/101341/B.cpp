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
	string S;
	cin >> S;

	vector <int> A;

	string T = "happiness";

	if(S.size() < T.size())
	{
		cout << "YES" << endl;
		cout << 1 << " " << 2 << endl;

		return 0;
	}

	for(int i = 0; i < S.size(); i++)
	{
		int f = 1;

		for(int j = 0; j < T.size(); j++)
		{
			if(i + j >= S.size())
			{
				f = 0;
				break;
			}

			if(T[j] != S[i + j])
			{
				f = 0;
				break;
			}
		}

		if(f)
			A.pb(i + 1);
	}

	if(A.size() > 2)
	{
		cout << "NO" << endl;
		return 0;
	}

	if(A.empty())
	{
		swap(S[0], S[1]);

		int f = 0;
		for(int i = 0; i < T.size(); i++)
			if(S[i] != T[i])
				f = 1;

		if(f)
		{
			cout << "YES" << endl;
			cout << 1 << " " << 2 << endl;

			return 0;
		}

		cout << "YES" << endl;
		cout << 2 << " " << 3 << endl;

		return 0;
	}

	cout << "YES" << endl;
	if(A.size() == 1)
	{
		cout << A[0] << " " << A[0] + 1 << endl;
	}
	else
	{
		cout << A[0] << " " << A[1] + 1 << endl;
	}

	return (0-0);	
}