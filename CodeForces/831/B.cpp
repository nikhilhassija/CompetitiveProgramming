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
	string A, B, C;
	cin >> A >> B >> C;

	int I[26];
	for(int i = 0; i < 26; i++)
		I[A[i] - 'a'] = i;

	for(int i = 0; i < C.size(); i++)
	{
		if(isdigit(C[i]))
			cout << C[i];
		else if(isupper(C[i]))
			cout << (char) toupper(B[I[C[i] - 'A']]);
		else
			cout << (char) B[I[C[i] - 'a']];
	}

	cout << endl;
	
	return (0-0);	
}