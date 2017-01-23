#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))
#define fastio() ios_base::sync_with_stdio(0);

using namespace std;

char A[10][10];

int checkh(int, int);
int checkv(int, int);
int checkd(int, int);
int good(int, int);

int main()
{
	string S[4];

	for(int i=0;i<4;i++)
		cin >> S[i];

	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			A[i][j] = 'o';

	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			A[i+2][j+2] = S[i][j];

	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(checkh(i+2, j+2) || checkv(i+2, j+2) || checkd(i+2, j+2))
			{
				printf("YES\n");
				return 0;
			}
		}
	}

	printf("NO\n");
}

int checkd(int x, int y)
{
	if((good(x-1, y-1) + good(x, y) + good(x+1, y+1)) > 4)
		return 1;

	if((good(x-1, y+1) + good(x, y) + good(x+1, y-1)) > 4)
		return 1;

	return 0;
}

int checkh(int x, int y)
{
	if((good(x, y-1) + good(x, y) + good(x, y+1)) > 4)
		return 1;

	return 0;
}


int checkv(int x, int y)
{
	if((good(x-1, y) + good(x, y) + good(x+1, y)) > 4)
		return 1;

	return 0;
}

int good(int x, int y)
{
	if(A[x][y] == '.')
		return 1;
	if(A[x][y] == 'x')
		return 2;

	return 0;
}

