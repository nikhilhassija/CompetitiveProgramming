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
	string A, B;
	cin >> A >> B;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	reverse(B.begin(), B.end());

	int n = A.size();

	int o_l = 0;
	int o_r = (n/2);
	int i_l = 0;
	int i_r = (n/2) - (n%2);

	char C[n+5];
	C[n] = 0;

	int l = 0;
	int r = n-1;

	for(int x=0; x<n; x++)
	{
		if(x % 2) // i
		{
			if(B[i_l] <= A[o_l])
				C[r--] = B[i_r--];
			else
				C[l++] = B[i_l++];
		}
		else // o
		{
			if(A[o_l] > B[i_l])
				C[r--] = A[o_r--];
			else
				C[l++] = A[o_l++];
		}
	}

	cout << C << endl;

	return (0-0);	
}