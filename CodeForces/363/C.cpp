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

	string T = "";
	for(char c: S)
	{
		if(T.size() < 2)
		{
			T.pb(c);
			continue;
		}

		if(c == T[T.size() - 1] and c == T[T.size() - 2])
			continue;

		T.pb(c);
	}

	vector < pair < char, int> > A;
	A.pb({T[0], 1});

	for(int i = 1; i < T.size(); i++)
	{
		if(T[i] == T[i - 1])
			A[A.size() - 1].second++;
		else
			A.pb({T[i], 1});
	}

	for(int i = 1; i < A.size(); i++)
		if(A[i].second == 2 and A[i - 1].second == 2)
			A[i].second = 1;

	for(int i = 0; i < A.size(); i++)
		for(int j = 0; j < A[i].second; j++)
			cout << A[i].first;

	cout << endl;

	return (0-0);	
}