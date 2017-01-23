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

vector <int> P;

int find(int);
void merge(int, int);

int main()
{
	int n;
	cin >> n;

	P.resize(n);

	for(int i=0;i<n;i++)
		P[i] = i;

	for(int i=0;i<n;i++)
	{
		int x;
		cin >> x;

		merge(i, x-1);
	}

	set <int> S;
	for(int i=0;i<n;i++)
		S.insert(find(i));

	cout << S.size() << endl;
}

int find(int v)
{
	if(P[v] == v)
		return v;

	return P[v] = find(P[v]);
}

void merge(int a, int b)
{
	int x = find(a);
	int y = find(b);

	if(x < y)
		P[y] = x;
	else
		P[x] = y;
}