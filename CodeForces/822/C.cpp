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

const int MAX_N = 2e5 + 5;

vector < int > D;

void insert(pair <pii, int>, int);
int find(int, int);

bool comp(pair <pii, int> &a, pair <pii, int> &b)
{
	return a.first.second < b.first.second;
}

int main()
{
	D.resize(MAX_N, -1);

	int n, x;
	cin >> n >> x;

	vector < pair < pii, int> > A(n);

	for(int i=0; i<n; i++)
		cin >> A[i].first.first >> A[i].first.second >> A[i].second;

	vector < pair <pii, int> > B(A.begin(), A.end());

	sort(A.begin(), A.end(), comp);
	sort(B.begin(), B.end());

	int k = 0;

	int ans = -1	;

	for(int i=0; i<n; i++)
	{
		while(A[k].first.second < B[i].first.first and k < A.size())
		{
			insert(A[k], x);
			k++;
		}

		int dur = B[i].first.second - B[i].first.first + 1;
		
		if(dur >= x)
			continue;

		int cur = find(x - dur, B[i].second);

		if(cur != -1)
		{
			if(ans == -1)
				ans = cur;
			else
				ans = min(ans, cur);
		}
	}

	cout << ans << endl;

	return (0-0);	
}

void insert(pair <pii, int> p, int x)
{
	int dur = p.first.second - p.first.first + 1;

	if(dur >= x)
		return;

	if(D[dur] == -1)
		D[dur] = p.second;
	else
		D[dur] = min(D[dur], p.second);
}

int find(int dur, int c)
{
	if(D[dur] == -1)
		return -1;

	return c + D[dur];
}