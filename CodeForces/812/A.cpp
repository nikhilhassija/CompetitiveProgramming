#include <bits/stdc++.h>

#define lli long long int
#define mset(x) memset(x, 0, sizeof(x))
#define fastio() ios_base::sync_with_stdio(0)

#define L 0
#define S 1
#define R 2
#define P 3

using namespace std;

int main()
{
	int A[4][4];
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			cin >> A[i][j];

	int B[4];
	mset(B);

	for(int i=0; i<4; i++)
		for(int j=0; j<3; j++)
			B[i] += A[i][j];

	if(A[0][P])
	{
		if(B[0] or A[1][L] or A[2][S] or A[3][R])
		{
			cout << "YES" << endl;
			return 0;
		}
	}

	if(A[1][P])
	{
		if(B[1] or A[2][L] or A[3][S] or A[0][R])
		{
			cout << "YES" << endl;
			return 0;
		}
	}

	if(A[2][P])
	{
		if(B[2] or A[3][L] or A[0][S] or A[1][R])
		{
			cout << "YES" << endl;
			return 0;
		}
	}


	if(A[3][P])
	{
		if(B[3] or A[0][L] or A[1][S] or A[2][R])
		{
			cout << "YES" << endl;
			return 0;
		}
	}

	cout << "NO" << endl;

	return (0-0);	
}