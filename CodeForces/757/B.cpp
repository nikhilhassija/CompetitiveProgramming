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

const int MAX_N = 1e5 + 5;

vector <int> P;
int p[MAX_N];

void seive();

int main()
{
	fastio();

	seive();	

	int n;
	cin >> n;

	int A[n];
	for(int i=0;i<n;i++)
		cin >> A[i];

	int c[MAX_N];
	memset(c, 0, sizeof(c));

	for(int i=0;i<n;i++)
		c[A[i]]++;

	int C[P.size()];
	memset(C, 0, sizeof(C));

	lli ops = 0;
	for(int i=0;i<MAX_N;i++)
	{
		if(c[i])
		{
			for(int j=0;j<P.size() && P[j] <= i; j++)
			{
				if(i % P[j] == 0)
					C[j] += c[i];

				ops++;
			}
		}
	}

	int ans = 0;
	for(int i=0;i<P.size();i++)
	{
		ans = max(ans, C[i]);
	}

	if(ans == 0 && c[1])
	{
		ans = 1;
	}

	cout << ans << endl;

	// cout << ops << endl;
}

void seive()
{

	for(int i=2;i<MAX_N;i++)
	{
		if(!p[i])
		{
			P.pb(i);

			for(int j=2*i; j<MAX_N;j+=i)
				p[j] = 1;
		}
	}
}