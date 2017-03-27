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

int b = 1;
string next();

int main()
{
	int n, k;
	cin >> n >> k;

	string A[n];
	for(int i=0; i<k; i++)
		A[i] = next();

	int x = n - k + 1;
	int i = k - 1;

	while(x--)
	{
		string S;
		cin >> S;

		if(S == "NO")
		{
			A[i] = A[i-k+1];
		}
		else
			A[i] = next();

		i++;
	}

	for(int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;

	return (0-0);	
}

string name(string S)
{
	S[0] = S[0] - 'a' + 'A';
	return S;
}

string next()
{
	int x = b;

	string S = "";

	while(x)
	{
		S.pb('a' + x%26);
		x /= 26;
	}

	b++;

	return name(S);
}