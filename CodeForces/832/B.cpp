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

string G;
int A[26];
string S;

void f1(string);
void f2(string, string);

int main()
{
	mset(A);

	cin >> G;
	for(int i = 0; i < G.size(); i++)
		A[G[i] - 'a'] = 1;

	cin >> S;

	int has = -1;
	for(int i = 0; i < S.size(); i++)
		if(S[i] == '*')
			has = i;

	if(has == -1)
	{
		f1(S);
	}
	else
	{
		f2(S.substr(0, has), S.substr(has + 1));
	}

	return (0-0);	
}

void f1(string T)
{
	int q;
	cin >> q;

	while(q--)
	{
		string S;
		cin >> S;

		if(T.size() != S.size())
		{
			cout << "NO" << endl;
			continue;
		}

		int ans = 1;
		for(int i = 0; i < T.size(); i++)
		{
			if(T[i] == '?')
			{
				if(A[S[i] - 'a'] == 0)
					ans = 0;
			}
			else if(T[i] != S[i])
				ans = 0;
		}

		if(ans)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}

void f2(string P, string S)
{
	int q;
	cin >> q;

	while(q--)
	{
		string T;
		cin >> T;

		if(T.size() < (P.size() + S.size()))
		{
			cout << "NO" << endl;
			continue;
		}

		int n = T.size();

		int l = P.size();
		int r = n - S.size();

		int ans = 1;

		for(int i = 0; i < l; i++)
		{
			if(P[i] == '?')
			{
				if(A[T[i] - 'a'] == 0)
					ans = 0;
			}
			else if(T[i] != P[i])
				ans = 0;
		}

		for(int i = l; i < r; i++)
			if(A[T[i] - 'a'])
				ans = 0;

		for(int i = r; i < n; i++)
		{
			if(S[i - r] == '?')
			{
				if(A[T[i] - 'a'] == 0)
					ans = 0;
			}
			else if(T[i] != S[i - r])
				ans = 0;
		}

		if(ans)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}