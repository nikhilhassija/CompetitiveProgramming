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

const int MAX_N = 150000 + 5;

int P[MAX_N];
int S[MAX_N];

void init();
int find(int);
void merge(int, int);
lli nc2(lli);

int main()
{
	int n, m;
	cin >> n >> m;

	assert(MAX_N > n);

	lli e = m;

	init();
	
	while(m--)
	{
		int x, y;
		cin >> x >> y;

		merge(x, y);
	}	

	for(int i=0; i<=n; i++)
	{
		int x = find(i);

		e -= nc2(S[x]);
		S[x] = 0;
	}

	if(e)
		printf("NO\n");
	else
		printf("YES\n");

	return (0-0);	
}

void init()
{
	for(int i=0; i<MAX_N; i++)
	{
		P[i] = i;
		S[i] = 1;
	}
}

int find(int x)
{
	if(x == P[x])
		return x;

	return P[x] = find(P[x]);
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	
	if(a == b)
		return ;

	P[b] = a;	
	S[a] += S[b];
}

lli nc2(lli n)
{
	return (n * (n-1)) / 2;
}